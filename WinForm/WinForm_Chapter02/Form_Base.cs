using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormTest01_Base
{
    public partial class Form_Base : Form
    {
        int EncMode = 0; // 0 : UTF-8, 1 : ANSI

        public Form_Base()
        {
            InitializeComponent(); // 생성자
            if (EncMode == 0) menuUtf8_Click(null, null);
            else menuAnsi_Click(null, null);
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            menuOpen_Click(sender, e);
        }

        string ReadBuf;
        Encoding enc = Encoding.UTF8; // Windows 기본
        private void menuOpen_Click(object sender, EventArgs e)
        {
            DialogResult ret = openFileDialog1.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string fn = openFileDialog1.FileName; // 파일의 전체경로
                FileStream fs = new FileStream(fn, FileMode.Open);
                StreamReader sr = new StreamReader(fs, enc); // 
                tbMemo.Text += sr.ReadToEnd();
                sr.Close();
                fs.Close();

                //while (true) // C#에서 무한루프 사용시 bool값(true, false)으로 설정  
                //{
                //    string str = sr.ReadLine();
                //    if (str == null) break;
                //    tbMemo.Text += str;
            }
        }

        private void menuSave_Click(object sender, EventArgs e)
        {
            DialogResult ret = saveFileDialog1.ShowDialog();
            if (ret == DialogResult.OK)
            {
                string fn = saveFileDialog1.FileName; // 파일의 전체경로
                FileStream fs = new FileStream(fn, FileMode.Create);
                StreamWriter sw = new StreamWriter(fs, enc);
                sw.Write(tbMemo.Text);
                sw.Close();
                fs.Close();
            }
        }

        private void menuAnsi_Click(object sender, EventArgs e)
        {  // UTF-8 ==> ANSI
            sbLabel1.Text = "ANSI";
            menuAnsi.Checked = true; 
            menuUtf8.Checked = false;
            enc = Encoding.Default;
            //byte[] ba = Encoding.ASCII.GetBytes(tbMemo.Text);
            //byte[] bb = Encoding.Convert(Encoding.UTF8, Encoding.Default, ba);
            //tbMemo.Text = Encoding.Default.GetString(bb);
        }

        private void menuUtf8_Click(object sender, EventArgs e)
        {
            sbLabel1.Text = "UTF-8";
            menuUtf8.Checked = true;
            menuAnsi.Checked = false;
            enc = Encoding.UTF8;
        }

        private void menuAbout_Click(object sender, EventArgs e)
        {
            string s = "";
            form_About frm = new form_About();
            DialogResult r = frm.ShowDialog();

            if (r == DialogResult.OK) s = "About.....OK";
            else                      s = "About.....Cancel";
            
            sbLabel2.Text = s;
        }
    }

}
