using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TourWH
{
    
    public partial class People : Form
    {
        string pname;
        string purl;
        public People(string name, string url)
        {
            InitializeComponent();
            this.pname = name;
            this.purl = url;
        }

        private void People_Load(object sender, EventArgs e)
        {
            textBox1.Text = pname;
            textBox2.Text = purl;
            string url = purl;
            webBrowser1.Navigate(url);

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
