using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
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

        private void Row_TextChanged(object sender, EventArgs e)
        {

        }

        private void Col_TextChanged(object sender, EventArgs e)
        {

        }

        private void UpdateBtn_Click(object sender, EventArgs e)
        {
            
            var posx = int.Parse(this.Col.Text) - 1;
            var posy = int.Parse(this.Row.Text) - 1;
            var posupdate = posx + posy * 8;
            this.topform.controlador._caballo.moveToPos(this.topform.controlador.table.casilla[posupdate]);

            this.topform.Refresh();
        }
    }
}
