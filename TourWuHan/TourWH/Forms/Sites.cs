using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ESRI.ArcGIS.Controls;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.Geodatabase;
using ESRI.ArcGIS.Geometry;
using TourWH.Classes;
using ESRI.ArcGIS.Display;
using ESRI.ArcGIS.NetworkAnalyst;
using ESRI.ArcGIS.SystemUI;
using System.Data.OleDb;
using DevComponents.DotNetBar;
using BaseLibs;

namespace TourWH.Forms
{
    public partial class Sites : DevComponents.DotNetBar.Office2007Form
    {
        enum traveltype
        {
            自然 = 1,
            人文 = 2,
            娱乐 = 3,
        }
        public string type;
        private AxMapControl mMapControl;
        //选中图层 
        private IFeatureLayer mFeatureLayer = null;
        //根据所选择的图层查询得到的特征类
        private IFeatureClass pFeatureClass = null;
        private List<string> path = new List<string>();//存储图片路径
        private int i = 0;
        private string path1 = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase;
        private bool entry = true;

        public Sites(AxMapControl mapControl)
        {
            InitializeComponent();
            this.mMapControl = mapControl;      
            
        }

        private void test_Load(object sender, EventArgs e)
        {
            if (this.mMapControl.LayerCount <= 0)
                return;
            ILayer pLayer;
            for (int i = 0; i < this.mMapControl.LayerCount; i++)
            {
                pLayer = this.mMapControl.get_Layer(i);
                if (pLayer.Name == "points")
                {
                    mFeatureLayer = pLayer as IFeatureLayer;
                    break;
                }
            }
            pFeatureClass = mFeatureLayer.FeatureClass;
                        
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
            comboBox3.SelectedIndex = 0;
            listBox1.SelectedIndex = 0;
        }    

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (entry == false)
            {
                listBox1.Items.Clear();
                int typeid = 0;
                switch (comboBox1.Text)
                {
                    case "自然": typeid = 1; break;
                    case "人文": typeid = 2; break;
                    case "娱乐": typeid = 3; break;
                }
                IQueryFilter pQueryFilter = new QueryFilterClass();
                //设置查询过滤条件  
                pQueryFilter.WhereClause = "traveltype = " + typeid.ToString();
                if (comboBox2.Text != "不限")
                    pQueryFilter.WhereClause += ("AND traveltime = " + comboBox2.Text);
                if (comboBox3.Text != "不限")
                    pQueryFilter.WhereClause += ("AND ticket = " + comboBox3.Text);
                
                //查询 ,search的参数第一个为过滤条件，第二个为是否重复执行
                IFeatureCursor pFeatureCursor = mFeatureLayer.Search(pQueryFilter, false);
                //获取查询到的要素 
                IFeature pFeature = pFeatureCursor.NextFeature();

                IField pField = null;
                string sFieldName = "name";
                int iFieldIndex = 0;
                iFieldIndex = pFeatureClass.FindField(sFieldName);
                pField = pFeatureClass.Fields.get_Field(iFieldIndex);

                while (pFeature != null)
                {
                    listBox1.Items.Add(pFeature.get_Value(iFieldIndex)); 
                    pFeature = pFeatureCursor.NextFeature();
                }
                if (listBox1.Items.Count == 0)
                    MessageBox.Show("没有符合条件的景点");
                else
                    listBox1.SelectedIndex = 0;  
            }          
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (entry == false)
            {
                listBox1.Items.Clear();
                pFeatureClass = mFeatureLayer.FeatureClass;
                int typeid = 0;
                switch (comboBox1.Text)
                {
                    case "自然": typeid = 1; break;
                    case "人文": typeid = 2; break;
                    case "娱乐": typeid = 3; break;
                }
                IQueryFilter pQueryFilter = new QueryFilterClass();
                //设置查询过滤条件
                pQueryFilter.WhereClause = "traveltype = " + typeid.ToString();
                if (comboBox2.Text != "不限")
                    pQueryFilter.WhereClause += ("AND traveltime = " + comboBox2.Text);
                if (comboBox3.Text != "不限")
                    pQueryFilter.WhereClause += ("AND ticket = " + comboBox3.Text);
                //查询 ,search的参数第一个为过滤条件，第二个为是否重复执行
                IFeatureCursor pFeatureCursor = mFeatureLayer.Search(pQueryFilter, false);
                //获取查询到的要素 
                IFeature pFeature = pFeatureCursor.NextFeature();

                IField pField = null;
                string sFieldName = "name";
                int iFieldIndex = 0;
                iFieldIndex = pFeatureClass.FindField(sFieldName);
                pField = pFeatureClass.Fields.get_Field(iFieldIndex);

                while (pFeature != null)
                {
                    listBox1.Items.Add(pFeature.get_Value(iFieldIndex)); ;
                    pFeature = pFeatureCursor.NextFeature();
                }
                if (listBox1.Items.Count == 0)
                    MessageBox.Show("没有符合条件的景点");
                else
                    listBox1.SelectedIndex = 0; 
            }
            entry = false;                      
        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            pFeatureClass = mFeatureLayer.FeatureClass;
            int typeid = 0;
            switch (comboBox1.Text)
            {
                case "自然": typeid = 1; break;
                case "人文": typeid = 2; break;
                case "娱乐": typeid = 3; break;
            }
            IQueryFilter pQueryFilter = new QueryFilterClass();
            //设置查询过滤条件
            pQueryFilter.WhereClause = "traveltype = " + typeid.ToString();
            if (comboBox2.Text != "不限")
                pQueryFilter.WhereClause += ("AND traveltime = " + comboBox2.Text);
            if (comboBox3.Text != "不限")
                pQueryFilter.WhereClause += ("AND ticket = " + comboBox3.Text);
            //查询 ,search的参数第一个为过滤条件，第二个为是否重复执行
            IFeatureCursor pFeatureCursor = mFeatureLayer.Search(pQueryFilter, false);
            //获取查询到的要素 
            IFeature pFeature = pFeatureCursor.NextFeature();

            IField pField = null;
            string sFieldName = "name";
            int iFieldIndex = 0;
            iFieldIndex = pFeatureClass.FindField(sFieldName);
            pField = pFeatureClass.Fields.get_Field(iFieldIndex);

            while (pFeature != null)
            {
                listBox1.Items.Add(pFeature.get_Value(iFieldIndex)); 
                pFeature = pFeatureCursor.NextFeature();
            }
            if (listBox1.Items.Count == 0)
                MessageBox.Show("没有符合条件的景点");
            else
                listBox1.SelectedIndex = 0;
        }    

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            mMapControl.Map.ClearSelection(); //清除上次查询结果            

            ILayer pLayer;
            for (int i = 0; i < this.mMapControl.LayerCount; i++)
            {
                pLayer = this.mMapControl.get_Layer(i);
                if (pLayer.Name == "points")
                {
                    mFeatureLayer = pLayer as IFeatureLayer;
                    break;
                }
            }
            IActiveView pActiveView = mMapControl.Map as IActiveView;
            IGraphicsContainer pGrap = pActiveView as IGraphicsContainer;
            pGrap.DeleteAllElements();//清除marker图片

            IQueryFilter pQueryFilter = new QueryFilterClass();
            //设置查询过滤条件             
            pQueryFilter.WhereClause = "name = '" + listBox1.Text + "'";
            //查询 ,search的参数第一个为过滤条件，第二个为是否重复执行
            IFeatureCursor pFeatureCursor = mFeatureLayer.Search(pQueryFilter, false);
            //获取查询到的要素 
            IFeature pFeature = pFeatureCursor.NextFeature();
            while (pFeature != null)
            {
                mMapControl.Map.SelectFeature(mFeatureLayer, pFeature); //选择要素 

                //添加marker
                IColor pColor;
                IRgbColor pRgbColor = new RgbColorClass();
                pRgbColor.Red = 255;
                pRgbColor.Green = 255;
                pRgbColor.Blue = 255;
                pColor = pRgbColor as IColor;
                IPictureMarkerSymbol pms = new PictureMarkerSymbolClass();
                pms.BitmapTransparencyColor = pColor;
                string picturePath = getPath(path1) + "\\Image\\景点.png";
                //添加自定义站点图片
                pms.CreateMarkerSymbolFromFile(esriIPictureType.esriIPicturePNG, picturePath);
                pms.Size = 30;
                IMarkerElement pMarkerEle = new MarkerElementClass();
                pMarkerEle.Symbol = pms as IMarkerSymbol;
                IElement pEle = pMarkerEle as IElement;
                pEle.Geometry = pFeature.Shape as IGeometry;                
                pGrap.AddElement(pEle, 1);

                //放大到要素
                IPoint mPoint = pFeature.Shape as IPoint;
                double expand = 0.05;
                ITopologicalOperator mTopoOperator =  mPoint as ITopologicalOperator;
                IPolygon mPolygonBuffer = mTopoOperator.Buffer(expand) as IPolygon;
                mMapControl.Extent = mPolygonBuffer.Envelope;

                pFeature = pFeatureCursor.NextFeature();
            }
            pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null);
            pActiveView.Refresh();//刷新图层

            SetPic(listBox1.Text);
        }

        private void SetPic(string tName)
        {
            path.Clear();
            string p = getPath(path1) + "\\Pics\\";
            string dbAdr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + @"PlacePics.mdb";
            OleDbConnection conn = new OleDbConnection(dbAdr);
            conn.Open();
            string strsql = "select [图片地址] from [Pics] where [景点名称]='"+ tName + "'";         
            OleDbCommand cmd = new OleDbCommand(strsql, conn);
            OleDbDataAdapter ad = new OleDbDataAdapter();
            ad.SelectCommand = cmd;
            DataTable dt = new DataTable();
            ad.Fill(dt);            
            path.Add(dt.Rows[0][0].ToString());            
            pictureBox1.Image = Image.FromFile(getPath(path1) + path[0]);
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        public string getPath(string path)
        {
            int t;
            t = path.IndexOf("bin");
            string name = path.Substring(0, t - 1);
            return name;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            i = listBox1.SelectedIndex;
            i--;
            if (i < 0)
            {
                i = listBox1.Items.Count - 1;
            }
            listBox1.SelectedIndex = i;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            i = listBox1.SelectedIndex;
            i++;
            if (i > listBox1.Items.Count - 1)
            {
                i = 0;//到最后一张，返回第一张
            }
            listBox1.SelectedIndex = i;
        }

        private void test_FormClosing(object sender, FormClosingEventArgs e)
        {
            mMapControl.Map.ClearSelection(); //清除上次查询结果   
            IActiveView pActiveView = mMapControl.Map as IActiveView;
            IGraphicsContainer pGrap = pActiveView as IGraphicsContainer;
            pGrap.DeleteAllElements();//清除marker图片
            pActiveView.Refresh();//刷新图层
        }

        private void Near_Click(object sender, EventArgs e)
        {
            ISelection selection = mMapControl.Map.FeatureSelection;
            IEnumFeatureSetup enumFeatureSetup = selection as IEnumFeatureSetup;
            enumFeatureSetup.AllFields = true;
            IEnumFeature enumFeature = enumFeatureSetup as IEnumFeature;
            enumFeature.Reset();
            IFeature feature = enumFeature.Next();
            IPoint center = feature.Shape as IPoint;
            AreaNear a = new AreaNear(mMapControl,center);            
            a.Show();
        }

        private void Sites_FormClosed(object sender, FormClosedEventArgs e)
        {
            ESRI.ArcGIS.SystemUI.ICommand Pan = new ControlsMapPanToolClass();
            Pan.OnCreate(mMapControl.Object);
            Pan.OnClick();
            mMapControl.CurrentTool = (ITool)Pan;
        }    

    }
}

