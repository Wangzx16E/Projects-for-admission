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

namespace TourWH.Forms
{
    public partial class AreaNear : DevComponents.DotNetBar.Office2007Form
    {
        private AxMapControl mMapControl;
        private IFeatureLayer mFeatureLayer;
        private string path1 = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase;
        private IPoint center = null;//缓冲区生成点
        
        public AreaNear(AxMapControl mapControl,IPoint c)
        {
            InitializeComponent();
            this.mMapControl = mapControl;
            this.center = c;
        }               

        private void FindThisHere(String textq,double bff)
        {
            IActiveView pActiveView = mMapControl.Map as IActiveView;
            IFeatureClass pFeatureClass = mFeatureLayer.FeatureClass;

            IPoint pPoint = center;//中心点        
           
            //创建缓冲区
            ITopologicalOperator pTopo;
            pTopo = pPoint as ITopologicalOperator;
            IGeometry pBuffer;
            pBuffer = pTopo.Buffer(bff);
            IGeometry pGeometry = pBuffer.Envelope;
            ISpatialFilter pSpatialFilter;
            pSpatialFilter = new SpatialFilterClass();
            pSpatialFilter.Geometry = pGeometry;
            pSpatialFilter.SpatialRel = esriSpatialRelEnum.esriSpatialRelContains;
            IFeatureCursor pFeatureCursor = pFeatureClass.Search(pSpatialFilter, false);
            IFeature pFeature = pFeatureCursor.NextFeature();
                       
            bool featurenull = false;
            if (pFeature == null)
            {
                featurenull = true;
                String tip = "抱歉，在该点附近没有您要找的地点！";
                MessageBox.Show(tip.ToString());
                pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null);
            }
            int count = 0;
            while (pFeature != null)
            {
                string fieldName = "type";
                IFields fields = mFeatureLayer.FeatureClass.Fields;
                int fieldIndex = fields.FindField(fieldName);
                if (pFeature.get_Value(fieldIndex).ToString() == textq)
                {
                    count++;
                    mMapControl.Map.SelectFeature(mFeatureLayer, pFeature);
                    IPoint POI = pFeature.Shape as IPoint;
                    AddMarker(POI);
                }
                
                pFeature = pFeatureCursor.NextFeature();
            }
            if (count == 0 && featurenull == false)
            {
                String tip = "抱歉，在该点附近没有您要找的地点！";
                MessageBox.Show(tip.ToString());
                pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null);
            }            
            pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null); 
        }

        private void AreaNear_Load(object sender, EventArgs e)
        {            
            string layerName = "points";
            ILayer pLayer = null;
            for (int i = 0; i < mMapControl.LayerCount;i++ )
            {
                pLayer = mMapControl.get_Layer(i);
                if (pLayer.Name == layerName)
                {
                    mFeatureLayer = (IFeatureLayer)pLayer;
                    break;
                }
            }
        }


        public string getPath(string path)
        {
            int t;
            t = path.IndexOf("bin");
            string name = path.Substring(0, t - 1);
            return name;
        }

        public void AddMarker(IPoint pt)
        {
            IPictureMarkerSymbol pPicturemksb = new PictureMarkerSymbolClass();
            pPicturemksb.Size = 20;
            string picturePath = getPath(path1) + "\\Image\\周边1.png";
            pPicturemksb.CreateMarkerSymbolFromFile(esriIPictureType.esriIPicturePNG, picturePath);
            IMarkerElement pMarkerEle = new MarkerElement() as IMarkerElement;
            pMarkerEle.Symbol = pPicturemksb as IMarkerSymbol;
            IElement pEle = (IElement)pMarkerEle;
            pEle.Geometry = pt;
            IGraphicsContainer pGraphicsContainer = mMapControl.ActiveView.GraphicsContainer;
            pGraphicsContainer.AddElement(pEle, 0);
            mMapControl.ActiveView.PartialRefresh(esriViewDrawPhase.esriViewGraphics, null, null);
        }

        private void buttonX1_Click(object sender, EventArgs e)
        {
            FindThisHere("bank", 0.02);
            this.Close();
        }

        private void buttonX2_Click(object sender, EventArgs e)
        {
            FindThisHere("hotel", 0.02);
            this.Close();
        }

        private void buttonX3_Click(object sender, EventArgs e)
        {
            FindThisHere("subway_entrance", 0.05);
            this.Close();
        }

        private void buttonX4_Click(object sender, EventArgs e)
        {
            FindThisHere("fast_food", 0.02);
            this.Close();
        }

        private void buttonX5_Click(object sender, EventArgs e)
        {
            FindThisHere("restaurant", 0.02);
            this.Close();
        }

        private void buttonX6_Click(object sender, EventArgs e)
        {
            FindThisHere("fuel", 0.05);
            this.Close();
        }

        private void buttonX7_Click(object sender, EventArgs e)
        {
            FindThisHere("hospital", 0.05);
            this.Close();
        }

        private void buttonX8_Click(object sender, EventArgs e)
        {
            FindThisHere("parking", 0.05);
            this.Close();
        }

        private void buttonX9_Click(object sender, EventArgs e)
        {
            FindThisHere("bus_stop", 0.01);
            this.Close();
        }
    }
}
