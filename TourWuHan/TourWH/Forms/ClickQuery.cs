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
using TourWH.Forms;
using TourWH.Classes;
using ESRI.ArcGIS.Display;
using ESRI.ArcGIS.SystemUI;

namespace TourWH.Forms
{
    public partial class ClickQuery : DevComponents.DotNetBar.Office2007Form
    {
        private AxMapControl mMapControl;
        private bool entry = true;
        
        public ClickQuery()
        {
            InitializeComponent();
        }

        public ClickQuery(AxMapControl mapControl)
        {
            InitializeComponent();
            this.mMapControl = mapControl;
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;

        }


        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (entry == false)
            {
                mMapControl.Map.ClearSelection();
                ICommand pCommand;
                double d = GetDis();
                string t = GetQueryType();
                pCommand = new BufferPointTool(d, t);
                pCommand.OnCreate(mMapControl.Object);
                mMapControl.CurrentTool = pCommand as ITool;
                pCommand = null;
            }
            entry = false;
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            mMapControl.Map.ClearSelection();
            ICommand pCommand;
            double d = GetDis();
            string t = GetQueryType();
            pCommand = new BufferPointTool(d, t);
            pCommand.OnCreate(mMapControl.Object);
            mMapControl.CurrentTool = pCommand as ITool;
            pCommand = null;  
        }

        public double GetDis()
        {
            string dis = comboBox1.SelectedItem.ToString();
            double dist = 0;
            switch (dis) //0.01大约为1Km
            {
                case "200": dist = 0.002; break;
                case "500": dist = 0.005; break;
                case "800": dist = 0.008; break;
                case "1000": dist = 0.01; break;
                case "1500": dist = 0.015; break;
                case "2000": dist = 0.02; break;
                case "3000": dist = 0.03; break;
                case "5000": dist = 0.05; break;
            }
            return dist;
        }

        public string GetQueryType()
        {
            string typetext = comboBox2.SelectedItem.ToString();
            string qtext = null;
            switch (typetext) //0.01大约为1Km
            {
                case "银行": qtext = "bank"; break;
                case "美食": qtext = "restaurant"; break;
                case "快餐": qtext = "fast_food"; break;
                case "公交站": qtext = "bus_stop"; break;
                case "地铁站": qtext = "subway_entrance"; break;
                case "停车场": qtext = "parking"; break;
                case "加油站": qtext = "fuel"; break;
                case "医院": qtext = "hospital"; break;
                case "酒店": qtext = "hotel"; break;
            }
            return qtext;
        }

        private void ClickQuery_FormClosed(object sender, FormClosedEventArgs e)
        {
            mMapControl.Map.ClearSelection();
            IGraphicsContainer pGrap = mMapControl.ActiveView as IGraphicsContainer;
            pGrap.DeleteAllElements();//删除所添加的图片要素
            mMapControl.ActiveView.Refresh();//刷新图层
            mMapControl.CurrentTool = null;
            //Pan功能
            ESRI.ArcGIS.SystemUI.ICommand Pan = new ControlsMapPanToolClass();
            Pan.OnCreate(mMapControl.Object);
            Pan.OnClick();
            mMapControl.CurrentTool = (ITool)Pan;
        }
    }
}
