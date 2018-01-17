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
    public partial class intro : Form
    {
        List<int> index_had = new List<int>();
        public string iname;
        public string iurl;
        public intro()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string test1 = " ";
   



            for (int i = 0; i < checkedListBox1.Items.Count; i++)
            {
                if (checkedListBox1.GetItemChecked(i))
                {
                    index_had.Add(i);
                    test1 = test1 + Convert.ToString(i);
                }

            }
         

            MessageBox.Show("您去过的序号： " + test1 );
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ScriptRuntime pyRuntime = Python.CreateRuntime();
            dynamic obj = pyRuntime.UseFile(@"cities.py");

            IronPython.Runtime.List hadlst = new IronPython.Runtime.List();

            foreach (int i in index_had)
            {
                hadlst.Add(i);
            }

            string result = obj.getPeople(hadlst);
            iurl = obj.getUrl(hadlst);
            iname = result;
            MessageBox.Show("为你推荐：" + iname);

            People infofr = new People(iname, iurl);
            infofr.Show();

        }
    }
}
