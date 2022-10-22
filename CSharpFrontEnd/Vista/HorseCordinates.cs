using CSharpFrontEnd.Modelo;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CSharpFrontEnd.Vista
{
    public partial class HorseCordinates : Form
    {
        private Form1 topform;

        public HorseCordinates(Form1 _topForm)
        {
            InitializeComponent();
            this.topform = _topForm;
        }

        private void Row_TextChanged(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)13)
            {
                UpdateBtn_Click(sender, e);
                Debug.WriteLine("enter pressed");
            }
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
            
        }

        private void Col_TextChanged(object sender, KeyPressEventArgs e)
        {
            if(e.KeyChar == (char)13)
            {
                UpdateBtn_Click(sender, e);
                Debug.WriteLine("enter pressed");
            }
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
        }

        private void UpdateBtn_Click(object sender, EventArgs e)
        {
            
            if(this.Col.Text.Length > 0 && this.Row.Text.Length > 0)
            {
                var posx = int.Parse(this.Col.Text) - 1;
                var posy = int.Parse(this.Row.Text) - 1;
                var posupdate = posx + posy * 8;

                Archivos archivos = new Archivos("output.txt");
                archivos.setOutput(posx, posy);
                this.topform.controlador._caballo.moveToPos(this.topform.controlador.table.casilla[posupdate]);
                this.topform.Refresh();
                this.Hide();
            }
            
        }
    }
}
