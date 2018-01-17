using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Security.Permissions;


namespace TourWH
{
    [PermissionSet(SecurityAction.Demand, Name = "FullTrust")]

    [System.Runtime.InteropServices.ComVisible(true)]



    public partial class Route : DevComponents.DotNetBar.Office2007Form
    {
        public Route()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            string str_url1 = "file:///C:/Users/Owner/Desktop/TourWH/TourWH/map.html";
            Uri url1 = new Uri(str_url1);
            webBrowser1.Url = url1;
            webBrowser1.ObjectForScripting = this;

            string str_url2 = "file:///C:/Users/Owner/Desktop/TourWH/TourWH/map2.html";
            Uri url2 = new Uri(str_url2);
            webBrowser2.Url = url2;
            webBrowser2.ObjectForScripting = this;

            string str_url3 = "file:///C:/Users/Owner/Desktop/TourWH/TourWH/map3.html";
            Uri url3 = new Uri(str_url3);
            webBrowser3.Url = url3;
            webBrowser3.ObjectForScripting = this;


        }

    }
}
