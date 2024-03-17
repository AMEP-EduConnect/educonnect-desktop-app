#include "pch.h"
#include "GrupEstudi_ConsultarUI.h"
#include "GrupEstudi.h"
#include "GrupEstudiMembership.h"
#include "GrupEstudiService.h"
#include <vector>

namespace CppCLRWinFormsProject {

    GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI(void)
    {
        InitializeComponent();
    }

    void GrupEstudi_ConsultarUI::testbutton_Cancelar(System::Object^ sender, System::EventArgs^ e)
    {
        //possar que torni al menu anterior
        this->Close();
    }

    void GrupEstudi_ConsultarUI::listBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e)
    {
        /* //Crear una instancia de GrupEstudiService (suponiendo que ya está implementado)
        GrupEstudiService consultar;

        // Obtener los grupos del usuario con la ID especificada
        std::vector<String^> gruposUsuario = consultar.ObtenerGruposUsuario(userId);

        // Limpiar el ListBox antes de cargar los nuevos grupos
        listaNoms->Items->Clear();

        // Llenar el ListBox con los grupos obtenidos
        for (String^ grupo : gruposUsuario)
        {
            // Convertir std::string a System::String
            System::String^ nombreGrupo = gcnew System::String(grupo.c_str());

            // Agregar el nombre del grupo al ListBox
            listaNoms->Items->Add(nombreGrupo);

        }*/
    }

    /*void GrupEstudi_ConsultarUI::GrupEstudi_ConsultarUI_Load(System::Object^ sender, System::EventArgs^ e)
    {
        // Suponiendo que userId es el ID del usuario actual
        int userId = ObtenerIdUsuarioActual();

        // Cargar los grupos del usuario
        CargarGruposUsuario(userId);
    }*/

}
