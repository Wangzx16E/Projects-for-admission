using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using IronPython.Hosting;
using Microsoft.Scripting.Hosting;

namespace TourWH
{
    public partial class Form1 : Form
    {
        List<int> index_must = new List<int>();
        List<int> index_want = new List<int>();
        public string pname = " ";
        public string purl = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string test1 = " ";
            string test2 = " ";



            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                if (checkedListBox1.GetItemChecked(i))
                {
                    index_must.Add(i);
                    test1 = test1 + Convert.ToString(i);
                }
               
            }
            for (int k = 0; k < checkedListBox2.Items.Count; k++)
            {
                if (checkedListBox2.GetItemChecked(k))
                {
                    index_want.Add(k);
                    test2 = test2 + Convert.ToString(k);
                }

            }

            MessageBox.Show("一定要去的序号： " +test1 + "   ； 想去的序号： " + test2 );

        }

        private void button2_Click(object sender, EventArgs e)
        {
            ScriptRuntime pyRuntime = Python.CreateRuntime();
            dynamic obj = pyRuntime.UseFile(@"recommend.py");

            IronPython.Runtime.List mustlst = new IronPython.Runtime.List();
            IronPython.Runtime.List wantlst = new IronPython.Runtime.List();

            foreach (int i in index_must)
            {
                mustlst.Add(i);
            }
            foreach (int i in index_want)
            {
                wantlst.Add(i);
            }

            string result = obj.getPeople(mustlst, wantlst);
            purl = obj.getUrl(mustlst, wantlst);
            pname = result;
            MessageBox.Show("为你推荐：" + pname);

            People infofr = new People(pname, purl);
            infofr.Show();
            
            


        }
    }
}
