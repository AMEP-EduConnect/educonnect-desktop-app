#include "pch.h"
#include "GrupEstudi.h"
#include "GrupEstudi_EditarUI.h"
#include "GrupEstudiService.h"


namespace CppCLRWinFormsProject {

    GrupEstudi_EditarUI::GrupEstudi_EditarUI(void)
    {
        InitializeComponent();
    }

    void GrupEstudi_EditarUI::testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e)
    {
        MessageBox::Show("Segur que vol sortir? No es guardarà cap modificació.");
        this->Close();
    }

    void GrupEstudi_EditarUI::testbutton_Edita(System::Object^ sender, System::EventArgs^ e)
    {
        GrupEstudiService editar;
        String^ group_name_act = textBox_NomActual->Text;
        String^ group_name_new = textBox_NomEditar->Text;
        String^ description_new = textBox_DescripcioEditar->Text;

        //Comprobar que el "group_name_act" existe;
        if (editar.existGroup(group_name_act)) {
            if (description_new != "") {
                editar.modifyGroupDescription(group_name_act, description_new);
            }

            if (group_name_new != "") {
                //Comprobar que el "group_name_new" no existe;
                if (not editar.existGroup(group_name_act)) {
                    editar.modifyGroupName(group_name_act, group_name_new);
                }
            }


            MessageBox::Show("S'ha editat correctament");
            //this->Close();
        }
        else {
            MessageBox::Show("No existeix cap grup amb aquest nom.");
        }
    }
}
