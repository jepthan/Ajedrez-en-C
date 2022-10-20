namespace CSharpFrontEnd.Vista
{
    partial class HorseCordinates
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.UpdateBtn = new System.Windows.Forms.Button();
            this.Row = new System.Windows.Forms.TextBox();
            this.Col = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // UpdateBtn
            // 
            this.UpdateBtn.Location = new System.Drawing.Point(129, 117);
            this.UpdateBtn.Name = "UpdateBtn";
            this.UpdateBtn.Size = new System.Drawing.Size(75, 23);
            this.UpdateBtn.TabIndex = 0;
            this.UpdateBtn.Text = "Update";
            this.UpdateBtn.UseVisualStyleBackColor = true;
            this.UpdateBtn.Click += new System.EventHandler(this.UpdateBtn_Click);
            // 
            // Row
            // 
            this.Row.Location = new System.Drawing.Point(68, 88);
            this.Row.Name = "Row";
            this.Row.Size = new System.Drawing.Size(188, 23);
            this.Row.TabIndex = 1;
            this.Row.TextChanged += new System.EventHandler(this.Row_TextChanged);
            // 
            // Col
            // 
            this.Col.Location = new System.Drawing.Point(68, 34);
            this.Col.Name = "Col";
            this.Col.Size = new System.Drawing.Size(188, 23);
            this.Col.TabIndex = 2;
            this.Col.TextChanged += new System.EventHandler(this.Col_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(68, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 25);
            this.label1.TabIndex = 3;
            this.label1.Text = "Columna";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.label2.Location = new System.Drawing.Point(68, 60);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 25);
            this.label2.TabIndex = 4;
            this.label2.Text = "Fila";
            // 
            // HorseCordinates
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(340, 152);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Col);
            this.Controls.Add(this.Row);
            this.Controls.Add(this.UpdateBtn);
            this.Name = "HorseCordinates";
            this.Text = "HorseCordinates";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Button UpdateBtn;
        private TextBox Row;
        private TextBox Col;
        private Label label1;
        private Label label2;
    }
}