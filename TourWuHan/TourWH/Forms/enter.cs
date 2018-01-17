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
    public partial class enter : DevComponents.DotNetBar.Office2007Form
    {
        public enter()
        {
            InitializeComponent();
        }

        private void buttonX1_Click(object sender, EventArgs e)
        {
            MainForm mainform = new MainForm();
            mainform.Show();
            this.Hide();
        }

        private void buttonX2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            /*if (label1.Left + label1.Width > 0)
            {
                label1.Left = label1.Left - 2;
            }
            else
            {
                label1.Left = this.Size.Width; // 移出则从头开始
            }*/
        }
    }
}
