using System;
using System.Drawing;
using System.Runtime.InteropServices;
using ESRI.ArcGIS.ADF.BaseClasses;
using ESRI.ArcGIS.ADF.CATIDs;
using ESRI.ArcGIS.Controls;
using System.Windows.Forms;
using ESRI.ArcGIS.Carto;
using ESRI.ArcGIS.Geodatabase;
using ESRI.ArcGIS.Geometry;
using ESRI.ArcGIS.Display;

namespace TourWH.Classes
{
    /// <summary>
    /// Summary description for BufferPointTool.
    /// </summary>
    [Guid("16ab5882-7ead-4714-828c-a02d81d5f8c1")]
    [ClassInterface(ClassInterfaceType.None)]
    [ProgId("TourWH.Classes.BufferPointTool")]
    public sealed class BufferPointTool : BaseTool
    {
        #region COM Registration Function(s)
        [ComRegisterFunction()]
        [ComVisible(false)]
        static void RegisterFunction(Type registerType)
        {
            // Required for ArcGIS Component Category Registrar support
            ArcGISCategoryRegistration(registerType);

            //
            // TODO: Add any COM registration code here
            //
        }

        [ComUnregisterFunction()]
        [ComVisible(false)]
        static void UnregisterFunction(Type registerType)
        {
            // Required for ArcGIS Component Category Registrar support
            ArcGISCategoryUnregistration(registerType);

            //
            // TODO: Add any COM unregistration code here
            //
        }

        #region ArcGIS Component Category Registrar generated code
        /// <summary>
        /// Required method for ArcGIS Component Category registration -
        /// Do not modify the contents of this method with the code editor.
        /// </summary>
        private static void ArcGISCategoryRegistration(Type registerType)
        {
            string regKey = string.Format("HKEY_CLASSES_ROOT\\CLSID\\{{{0}}}", registerType.GUID);
            MxCommands.Register(regKey);
            ControlsCommands.Register(regKey);
        }
        /// <summary>
        /// Required method for ArcGIS Component Category unregistration -
        /// Do not modify the contents of this method with the code editor.
        /// </summary>
        private static void ArcGISCategoryUnregistration(Type registerType)
        {
            string regKey = string.Format("HKEY_CLASSES_ROOT\\CLSID\\{{{0}}}", registerType.GUID);
            MxCommands.Unregister(regKey);
            ControlsCommands.Unregister(regKey);
        }

        #endregion
        #endregion

        IMap pMap;
        IActiveView pActiveView;
        IHookHelper m_hookHelper = new HookHelperClass();
        private IFeatureLayer mFeatureLayer;
        public double bufferdis;
        private string path1 = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase;
        public string type;

        public BufferPointTool(double dis, string t)
        {
            //
            // TODO: Define values for the public properties
            //
            base.m_category = "SelctionBasedonPoint"; //localizable text 
            base.m_caption = "SelctionBasedonPoint";  //localizable text 
            base.m_message = "SelctionBasedonPoint";  //localizable text
            base.m_toolTip = "SelctionBasedonPoint";  //localizable text
            base.m_name = "SelctionBasedonPoint";   //unique id, non-localizable (e.g. "MyCategory_MyTool")
            try
            {
                //
                // TODO: change resource name if necessary
                //
                string bitmapResourceName = GetType().Name + ".bmp";
                base.m_bitmap = new Bitmap(GetType(), bitmapResourceName);
                base.m_cursor = new System.Windows.Forms.Cursor(GetType(), GetType().Name + ".cur");
                bufferdis = dis;
                type = t;
            }
            catch (Exception ex)
            {
                System.Diagnostics.Trace.WriteLine(ex.Message, "Invalid Bitmap");
            }
        }

        #region Overridden Class Methods

        /// <summary>
        /// Occurs when this tool is created
        /// </summary>
        /// <param name="hook">Instance of the application</param>
        public override void OnCreate(object hook)
        {
            try
            {
                m_hookHelper = new HookHelperClass();
                m_hookHelper.Hook = hook;
                if (m_hookHelper.ActiveView == null)
                {
                    m_hookHelper = null;
                }
            }
            catch
            {
                m_hookHelper = null;
            }

            if (m_hookHelper == null)
                base.m_enabled = false;
            else
                base.m_enabled = true;

            // TODO:  Add other initialization code
        }

        /// <summary>
        /// Occurs when this tool is clicked
        /// </summary>
        public override void OnClick()
        {
            // TODO: Add BufferPointTool.OnClick implementation
        }

        public override void OnMouseDown(int Button, int Shift, int X, int Y)
        {
            // TODO:  Add BufferPointTool.OnMouseDown implementation
            pActiveView = m_hookHelper.ActiveView;
            pMap = m_hookHelper.FocusMap;
            pMap.ClearSelection();
            IGraphicsContainer pGrap = pActiveView as IGraphicsContainer;
            pGrap.DeleteAllElements();//删除所添加的图片要素

            string layerName = "points";
            ILayer pLayer = null;
            for (int i = 0; i < pMap.LayerCount; i++)
            {
                pLayer = pMap.get_Layer(i);
                if (pLayer.Name == layerName)
                {
                    mFeatureLayer = (IFeatureLayer)pLayer;
                    break;
                }
            }
            IFeatureClass pFeatureClass = mFeatureLayer.FeatureClass;
            IPoint pPoint = pActiveView.ScreenDisplay.DisplayTransformation.ToMapPoint(X, Y);

            IPictureMarkerSymbol pPicturemksb = new PictureMarkerSymbolClass();
            pPicturemksb.Size = 30;
            string picturePath = getPath(path1) + "\\Image\\景点.png";
            pPicturemksb.CreateMarkerSymbolFromFile(esriIPictureType.esriIPicturePNG, picturePath);
            IMarkerElement pMarkerEle = new MarkerElement() as IMarkerElement;
            pMarkerEle.Symbol = pPicturemksb as IMarkerSymbol;
            IElement pEle = (IElement)pMarkerEle;
            pEle.Geometry = pPoint;
            IGraphicsContainer pGraphicsContainer = pActiveView.GraphicsContainer;
            pGraphicsContainer.AddElement(pEle, 0);
            pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGraphics, null, null);

            ITopologicalOperator pTopo;
            pTopo = pPoint as ITopologicalOperator;
            IGeometry pBuffer;
            pBuffer = pTopo.Buffer(bufferdis);
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
                String tip = "抱歉，在该点附近" + (bufferdis * 100000).ToString() + "米没有您要找的地点！";
                MessageBox.Show(tip.ToString());
                pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null);
            }
            int count = 0;
            while (pFeature != null)
            {
                string fieldName = "type";
                IFields fields = mFeatureLayer.FeatureClass.Fields;
                int fieldIndex = fields.FindField(fieldName);
                if (pFeature.get_Value(fieldIndex).ToString() == type)
                {
                    count++;
                    pMap.SelectFeature(mFeatureLayer, pFeature);
                    IPoint POI = pFeature.Shape as IPoint;
                    AddMarker(POI);
                }
                pFeature = pFeatureCursor.NextFeature();
            }
            if (count == 0 && featurenull == false)
            {
                String tip = "抱歉，在该点附近" + (bufferdis * 100000).ToString() + "米没有您要找的地点！";
                MessageBox.Show(tip.ToString());
                pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null);
            }

            pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGeoSelection, null, null); 
        }

        public override void OnMouseMove(int Button, int Shift, int X, int Y)
        {
            // TODO:  Add BufferPointTool.OnMouseMove implementation
        }

        public override void OnMouseUp(int Button, int Shift, int X, int Y)
        {
            // TODO:  Add BufferPointTool.OnMouseUp implementation
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
            IGraphicsContainer pGraphicsContainer = pActiveView.GraphicsContainer;
            pGraphicsContainer.AddElement(pEle, 0);
            pActiveView.PartialRefresh(esriViewDrawPhase.esriViewGraphics, null, null);

        }

        public string getPath(string path)
        {
            int t;
            t = path.IndexOf("bin");
            string name = path.Substring(0, t - 1);
            return name;
        }
        #endregion
    }
}
