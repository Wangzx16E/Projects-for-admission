using ESRI.ArcGIS.Controls;
using ESRI.ArcGIS.SystemUI;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TourWH.Forms
{
    public partial class FrmMeasureResult : DevComponents.DotNetBar.Office2007Form
    {
        private AxMapControl mMapControl;
        //声明运行结果关闭事件
        public delegate void FrmClosedEventHandler();
        public event FrmClosedEventHandler frmClosed = null;

        public FrmMeasureResult(AxMapControl mapControl)
        {
            InitializeComponent();
            this.mMapControl = mapControl;
        }

        //窗口关闭时引发委托事件
        private void FrmMeasureResult_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (frmClosed != null)
            {
                frmClosed();
            }
            ESRI.ArcGIS.SystemUI.ICommand Pan = new ControlsMapPanToolClass();
            Pan.OnCreate(mMapControl.Object);
            Pan.OnClick();
            mMapControl.CurrentTool = (ITool)Pan;
        }
    }
}
