using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using DevComponents.DotNetBar;
using ESRI.ArcGIS.Controls;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.esriSystem;
using ESRI.ArcGIS.Geodatabase;
using ESRI.ArcGIS.Display;
using ESRI.ArcGIS.SystemUI;
using ESRI.ArcGIS.Geometry;

using BaseLibs;
using TourWH.Forms;
using System.Data.OleDb;



namespace TourWH
{
    public partial class MainForm : Office2007RibbonForm
    {
        //调用写的地图操作类
        private MapView m_MapView = null;
        //长度、面积量算
        private FrmMeasureResult frmMeasureResult = null;    //量算结果窗体
        private INewLineFeedback pNewLineFeedback;           //追踪线对象
        private INewPolygonFeedback pNewPolygonFeedback;     //追踪面对象
        private IPoint pPointPt = null;                      //鼠标点击点
        private IPoint pMovePt = null;                       //鼠标移动时的当前点
        private double dToltalLength = 0;                    //量测总长度
        private double dSegmentLength = 0;                   //片段距离
        private IPointCollection pAreaPointCol = new MultipointClass();  //面积量算时画的点进行存储

        string pMouseOperate = null;                //鼠标点击区分的switch（可用在其他部分）
        private string sMapUnits = "未知单位";      //地图单位变量，在公共方法中赋值（可用在其他部分）
        private object missing = Type.Missing;
        
        //路线推荐的绑定显示
        BindingSource mybs = new BindingSource();

        public MainForm()
        {
            InitializeComponent();
        }               

        private void MainForm_Load(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;    //打开最大化         
            
            m_MapView = new MapView(this, axMapControl1);
            
            axMapControl1.LoadMxFile(@"地图数据\wuhan.mxd");//自动读入数据
            axMapControl1.get_Layer(0).MinimumScale = 264779;
            //以下为全图浏览功能
            m_MapView.CurMapOperation = MapOperation.MapFullScope;
            //以下为Pan功能
            ESRI.ArcGIS.SystemUI.ICommand Pan = new ControlsMapPanToolClass();
            Pan.OnCreate(axMapControl1.Object);
            Pan.OnClick();
            axMapControl1.CurrentTool = (ITool)Pan;
            ////////////////////////
            string mystr;
            OleDbConnection myconn = new OleDbConnection();
            DataSet myds1 = new DataSet();
            DataSet myds2 = new DataSet();
            mystr = "Provider=Microsoft.Jet.OLEDB.4.0;" + "Data Source=" + @"Tour.mdb";
            myconn.ConnectionString = mystr;
            myconn.Open();

            OleDbDataAdapter myda1 = new OleDbDataAdapter("SELECT distinct 几日游 FROM Tourline", myconn);
            myda1.Fill(myds1, "Tourline");
            comboBox1.DataSource = myds1.Tables["Tourline"];
            comboBox1.DisplayMember = "几日游";

            OleDbDataAdapter myda2 = new OleDbDataAdapter("SELECT distinct 类型 FROM Tourline", myconn);
            myda2.Fill(myds2, "Tourline");
            comboBox2.DataSource = myds2.Tables["Tourline"];
            comboBox2.DisplayMember = "类型";
            
            myconn.Close();
            comboBox1.Text = "";
            comboBox2.Text = "";
        }

        private void axMapControl1_OnMouseDown(object sender, IMapControlEvents2_OnMouseDownEvent e)      //地图单击 
        {
            //屏幕坐标点转化为地图坐标点
            pPointPt = (axMapControl1.Map as IActiveView).ScreenDisplay.DisplayTransformation.ToMapPoint(e.x, e.y);
            if (e.button == 1)   //左键
            {
                IActiveView pActiveView = axMapControl1.ActiveView;
                IEnvelope pEnvelope = new EnvelopeClass();
                switch (pMouseOperate)
                {
                    #region 距离量算
                    case "MeasureLength":
                        //判断追踪线对象是否为空，若是则实例化并设置当前鼠标点为起始点
                        if (pNewLineFeedback == null)
                        {
                            //实例化追踪线对象
                            pNewLineFeedback = new NewLineFeedbackClass();
                            pNewLineFeedback.Display = (axMapControl1.Map as IActiveView).ScreenDisplay;
                            //设置起点，开始动态线绘制
                            pNewLineFeedback.Start(pPointPt);
                            dToltalLength = 0;
                        }
                        else //如果追踪线对象不为空，则添加当前鼠标点
                        {
                            pNewLineFeedback.AddPoint(pPointPt);
                        }
                        if (dSegmentLength != 0)
                        {
                            dToltalLength = dToltalLength + dSegmentLength;
                        }
                        break;
                    #endregion
                    #region 面积量算
                    case "MeasureArea":
                        if (pNewPolygonFeedback == null)
                        {
                            //实例化追踪面对象
                            pNewPolygonFeedback = new NewPolygonFeedback();
                            pNewPolygonFeedback.Display = (axMapControl1.Map as IActiveView).ScreenDisplay;
                            pAreaPointCol.RemovePoints(0, pAreaPointCol.PointCount);
                            //开始绘制多边形
                            pNewPolygonFeedback.Start(pPointPt);
                            pAreaPointCol.AddPoint(pPointPt, ref missing, ref missing);
                        }
                        else
                        {
                            pNewPolygonFeedback.AddPoint(pPointPt);
                            pAreaPointCol.AddPoint(pPointPt, ref missing, ref missing);
                        }
                        break;    
                     #endregion
                    #region 其他
                    case "SelFeature":
                       //////////
                    #endregion
                    default:
                        break;
                }
            }
            else if (e.button == 2) //右键
            {
            }
        }
        private void axMapControl1_OnDoubleClick(object sender, IMapControlEvents2_OnDoubleClickEvent e)  //地图双击 
        {
            #region 长度量算
            if (pMouseOperate == "MeasureLength")
            {
                if (frmMeasureResult != null)
                {
                    frmMeasureResult.lblMeasureResult.Text = "量测的总路线距离为：" + dToltalLength + sMapUnits;
                }
                if (pNewLineFeedback != null)
                {
                    pNewLineFeedback.Stop();
                    pNewLineFeedback = null;
                    //清空所画的线对象
                    (axMapControl1.Map as IActiveView).PartialRefresh(esriViewDrawPhase.esriViewForeground, null, null);
                }
                dToltalLength = 0;
                dSegmentLength = 0;
            }
            #endregion
            #region 面积量算
            if (pMouseOperate == "MeasureArea")
            {
                if (pNewPolygonFeedback != null)
                {
                    pNewPolygonFeedback.Stop();
                    pNewPolygonFeedback = null;
                    //清空所画的线对象
                    (axMapControl1.Map as IActiveView).PartialRefresh(esriViewDrawPhase.esriViewForeground, null, null);
                }
                pAreaPointCol.RemovePoints(0, pAreaPointCol.PointCount); //清空点集中所有点
            }
            #endregion
        }
        private void axMapControl1_OnMouseMove(object sender, IMapControlEvents2_OnMouseMoveEvent e)      //地图移动
        {
            if (axMapControl1.LayerCount == 0) return;
            sMapUnits = "千米";//GetMapUnit(axMapControl1.Map.MapUnits);  //求量测所需的单位
            #region 状态栏
            //就绪
            
           
            //比例尺
            labelItem2.Text = " 比例尺 1:" + ((long)this.axMapControl1.MapScale).ToString();
            //坐标
            lbl_Coordinate.Text = "当前坐标：X:" + e.mapX.ToString() + " Y: " + e.mapY.ToString() ;
            #endregion

            pMovePt = (axMapControl1.Map as IActiveView).ScreenDisplay.DisplayTransformation.ToMapPoint(e.x, e.y);
            #region 长度量算
            if (pMouseOperate == "MeasureLength")
            {
                if (pNewLineFeedback != null)
                {
                    pNewLineFeedback.MoveTo(pMovePt);
                }
                double deltaX = 0; //两点之间X差值
                double deltaY = 0; //两点之间Y差值

                if ((pPointPt != null) && (pNewLineFeedback != null))
                {
                    deltaX = pMovePt.X - pPointPt.X;
                    deltaY = pMovePt.Y - pPointPt.Y;
                    dSegmentLength = Math.Round(111.199 * (Math.Sqrt((deltaY * deltaY) + (deltaX * deltaX) * (Math.Cos((pPointPt.Y+pMovePt.Y)/2)*Math.Cos((pPointPt.Y+pMovePt.Y)/2)))), 3);
                    dToltalLength = dToltalLength + dSegmentLength;
                    if (frmMeasureResult != null)
                    {
                        frmMeasureResult.lblMeasureResult.Text = String.Format(
                            "当前量测的距离为：{0:.###}{1};\r\n总长度为: {2:.###}{1}",
                            dSegmentLength, sMapUnits, dToltalLength);
                        dToltalLength = dToltalLength - dSegmentLength; //鼠标移动到新点重新开始计算
                    }
                    frmMeasureResult.frmClosed += new FrmMeasureResult.FrmClosedEventHandler(frmMeasureResult_frmColsed);
                }
            }
            #endregion
            #region 面积量算
            if (pMouseOperate == "MeasureArea")
            {
                if (pNewPolygonFeedback != null)
                {
                    pNewPolygonFeedback.MoveTo(pMovePt);
                }

                IPointCollection pPointCol = new Polygon();
                IPolygon pPolygon = new PolygonClass();
                IGeometry pGeo = null;

                ITopologicalOperator pTopo = null;
                for (int i = 0; i <= pAreaPointCol.PointCount - 1; i++)
                {
                    pPointCol.AddPoint(pAreaPointCol.get_Point(i), ref missing, ref missing);
                }
                pPointCol.AddPoint(pMovePt, ref missing, ref missing);

                if (pPointCol.PointCount < 3) return;
                pPolygon = pPointCol as IPolygon;

                if ((pPolygon != null))
                {
                    pPolygon.Close();
                    pGeo = pPolygon as IGeometry;
                    pTopo = pGeo as ITopologicalOperator;
                    //使几何图形的拓扑正确
                    pTopo.Simplify();
                    pGeo.Project(axMapControl1.Map.SpatialReference);
                    IArea pArea = pGeo as IArea;

                    frmMeasureResult.lblMeasureResult.Text = String.Format(
                        "总面积为：{0:.####}平方{1};\r\n总长度为：{2:.####}{1}",
                        pArea.Area, sMapUnits, pPolygon.Length);
                    pPolygon = null;
                }
            }
            #endregion
            #region 移动显示名称
            IFeatureLayer pFeatureLayer8 = axMapControl1.Map.get_Layer(0) as IFeatureLayer; //定位的图层包括了很多要素
            pFeatureLayer8.DisplayField = "name";
            pFeatureLayer8.ShowTips = true;
            string pTip8;
            pTip8 = pFeatureLayer8.get_TipText(e.mapX, e.mapY, axMapControl1.ActiveView.FullExtent.Width / 1000);
            if (pTip8 != null&&pTip8 != " ")
            {
                toolTip1.SetToolTip(axMapControl1, "这里是：" + pTip8);
            }
            else
            {
                toolTip1.SetToolTip(axMapControl1, "");
            }
            #endregion
        }

        #region 量测

        private void btnMeasureArea_Click(object sender, EventArgs e)   //面积量测
        {

        } 
        private void frmMeasureResult_frmColsed()                    //测量窗口关闭响应(原窗口的委托)  
        {
            //清空线对象
            if (pNewLineFeedback != null)
            {
                pNewLineFeedback.Stop();
                pNewLineFeedback = null;
            }
            //清空面对象
            if (pNewPolygonFeedback != null)
            {
                pNewPolygonFeedback.Stop();
                pNewPolygonFeedback = null;
                pAreaPointCol.RemovePoints(0, pAreaPointCol.PointCount); //清空点集中所有点
            }
            //清空量算画的线、面对象
            axMapControl1.ActiveView.PartialRefresh(esriViewDrawPhase.esriViewForeground, null, null);
            //结束量算功能
            pMouseOperate = string.Empty;
            axMapControl1.MousePointer = esriControlsMousePointer.esriPointerDefault;
        }
        #endregion

        #region 公共方法（其他）
        private int IndexLayerByName(string layerName)          //调用（依据名称获得图层在第几层）
        {
            IMap pMap = axMapControl1.Map;
            ILayer pLayer;
            int i;
            for (i = 0; i < pMap.LayerCount; i++)
            {
                pLayer = pMap.get_Layer(i);
                if (pLayer.Name == layerName)
                {
                    break;
                }
            }
            return i;
        }
        private string GetMapUnit(esriUnits _esriMapUnit)   //地图单位获取 
        {
            string sMapUnits = string.Empty;
            switch (_esriMapUnit)
            {
                case esriUnits.esriCentimeters:
                    sMapUnits = "厘米";
                    break;
                case esriUnits.esriDecimalDegrees:
                    sMapUnits = "十进制";
                    break;
                case esriUnits.esriDecimeters:
                    sMapUnits = "分米";
                    break;
                case esriUnits.esriFeet:
                    sMapUnits = "尺";
                    break;
                case esriUnits.esriInches:
                    sMapUnits = "英寸";
                    break;
                case esriUnits.esriKilometers:
                    sMapUnits = "千米";
                    break;
                case esriUnits.esriMeters:
                    sMapUnits = "米";
                    break;
                case esriUnits.esriMiles:
                    sMapUnits = "英里";
                    break;
                case esriUnits.esriMillimeters:
                    sMapUnits = "毫米";
                    break;
                case esriUnits.esriNauticalMiles:
                    sMapUnits = "海里";
                    break;
                case esriUnits.esriPoints:
                    sMapUnits = "点";
                    break;
                case esriUnits.esriUnitsLast:
                    sMapUnits = "UnitsLast";
                    break;
                case esriUnits.esriUnknownUnits:
                    sMapUnits = "未知单位";
                    break;
                case esriUnits.esriYards:
                    sMapUnits = "码";
                    break;
                default:
                    break;
            }
            return sMapUnits;
        }
        #endregion

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)//关闭窗体时关闭进入界面
        {
            Application.Exit();
        }
        
        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.DataBindings.Clear();
            textBox2.DataBindings.Clear();
            OleDbConnection myconn=new OleDbConnection();
            DataSet myds=new DataSet();
            string mystr="Provider=Microsoft.Jet.OLEDB.4.0;" + "Data Source=" + @"Tour.mdb";
            myconn.ConnectionString = mystr;
            myconn.Open();
            string condstr = "SELECT * FROM Tourline";
            if (comboBox1.Text != "")
                    condstr = condstr + " WHERE 几日游='" + comboBox1.Text + "'";
            if (comboBox2.Text != "")
                if (comboBox1.Text != "")
                    condstr = condstr + " AND 类型='" + comboBox2.Text + "'";
                else
                    condstr = condstr + " WHERE 类型='" + comboBox2.Text + "'";
            OleDbDataAdapter myda = new OleDbDataAdapter(condstr, myconn);
            myda.Fill(myds, "Tourline");
            mybs = new BindingSource(myds, "Tourline");
            Binding mybinding1 = new Binding("Text", mybs, "路线");
            textBox1.DataBindings.Add(mybinding1);
            Binding mybinding2 = new Binding("Text", mybs, "简介");
            textBox2.DataBindings.Add(mybinding2);
            string str1 = textBox1.Text;
            str1 = str1.Replace("、","->");
            str1 = str1.Replace("；", "\r\n\r\n");
            textBox1.Text = str1;
            myconn.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if(mybs.Position!=mybs.Count-1)
                mybs.MoveNext();
            string str1 = textBox1.Text;
            str1 = str1.Replace("、", "->");
            str1 = str1.Replace("；", "\r\n\r\n");
            textBox1.Text = str1;
        }

        private void buttonX2_Click(object sender, EventArgs e)
        {
            Sites t = new Sites(axMapControl1);
            t.Show();
        }

        private void buttonX1_Click(object sender, EventArgs e)
        {
            ClickQuery c = new ClickQuery(axMapControl1);
            c.Show();
        }

        private void buttonX3_Click(object sender, EventArgs e)
        {
            //距离
            axMapControl1.CurrentTool = null;
            pMouseOperate = "MeasureLength";
            axMapControl1.MousePointer = esriControlsMousePointer.esriPointerCrosshair;
            if (frmMeasureResult == null || frmMeasureResult.IsDisposed)
            {
                frmMeasureResult = new FrmMeasureResult(axMapControl1);
                frmMeasureResult.frmClosed += new FrmMeasureResult.FrmClosedEventHandler(frmMeasureResult_frmColsed);
                frmMeasureResult.lblMeasureResult.Text = "";
                frmMeasureResult.Text = "距离量测";
                frmMeasureResult.Show();
            }
            else
            {
                frmMeasureResult.Activate();
            }
            //面积
            /*
            axMapControl1.CurrentTool = null;
            pMouseOperate = "MeasureArea";
            axMapControl1.MousePointer = esriControlsMousePointer.esriPointerCrosshair;
            if (frmMeasureResult == null || frmMeasureResult.IsDisposed)
            {
                frmMeasureResult = new FrmMeasureResult();
                frmMeasureResult.frmClosed += new FrmMeasureResult.FrmClosedEventHandler(frmMeasureResult_frmColsed);
                frmMeasureResult.lblMeasureResult.Text = "";
                frmMeasureResult.Text = "面积量测";
                frmMeasureResult.Show();
            }
            else
            {
                frmMeasureResult.Activate();
            }
            */
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (mybs.Position != 0)
                mybs.MovePrevious();
            string str1 = textBox1.Text;
            str1 = str1.Replace("、", "->");
            str1 = str1.Replace("；", "\r\n\r\n");
            textBox1.Text = str1;
        }

        private void buttonX5_Click(object sender, EventArgs e)
        {
            expandableSplitter2.Expanded = true;
        }

        private void buttonX4_Click(object sender, EventArgs e)
        {
            Route c = new Route();
            c.Show();
        }

        private void buttonX7_Click(object sender, EventArgs e)
        {
            first c = new first();
            c.Show();
        }  

    }
}
