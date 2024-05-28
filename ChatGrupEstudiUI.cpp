#include "pch.h"
#include "ChatGrupEstudiUI.h"
#include "GrupEstudi.h"
#include "ChatGrupEstudiService.h"
#include "MessageManager.h"
#include <string>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
namespace CppCLRWinFormsProject {
    Void ChatGrupEstudiUI::sendButton_Click(System::Object^ sender, System::EventArgs^ e) {
       String^ message = this->messageTextBox->Text->Trim();
        if (!String::IsNullOrWhiteSpace(message)) {
            if(chatGrupEstudiService->SendMenssage(id_group, CurrentSession::Instance->GetCurrentUser()->GetUserId(), message) == false)
			{
				MessageManager::WarningMessage("Error al enviar el mensaje");
			}
            else 
            {
                //Consultar BD dia/hora
                DateTime^ date_time = DateTime::Now;
                String^ date2 = ConvertDate(date_time);
                String^ date3 = ConvertHour(date_time);

                if (this->date != date2) {
                    this->date = date2;
					chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Italic);
					chatListBox->SelectionAlignment = HorizontalAlignment::Center;
					chatListBox->AppendText(date2 + "\n");
				}
                chatListBox->SelectionAlignment = HorizontalAlignment::Right;
                if (message->Length > 15) message = FormatMessage(message);
                int start = chatListBox->TextLength;  
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->AppendText("Tú ["+ date3 +"]: ");
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                chatListBox->AppendText(message + "\n");
                int length = chatListBox->TextLength - start;  
                chatListBox->Select(start, length);
                //chatListBox->SelectionAlignment = HorizontalAlignment::Right;
                messageTextBox->Clear();
                chatListBox->SelectionCharOffset = 5;
                chatListBox->SelectionStart = chatListBox->TextLength;
                chatListBox->ScrollToCaret();
            }
        }
    }
  

    
    Void ChatGrupEstudiUI::ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e) {
        List<ChatMessage^>^ chatMembers = chatGrupEstudiService->GetChatMembers(id_group);
        Int64^ id_user = CurrentSession::Instance->GetCurrentUser()->GetUserId();

        System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers->GetEnumerator();
        ChatMessage^ lastMessage = nullptr;
        // First day write in the chat central
        System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator_day = chatMembers->GetEnumerator();
        if (enumerator_day->MoveNext()) {
            ChatMessage^ chatMessage_date = enumerator_day->Current;
            ConvertDate(chatMessage_date->getTimestamp());
            chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Italic);
            this->date = ConvertDate(chatMessage_date->getTimestamp());
            chatListBox->SelectionAlignment = HorizontalAlignment::Center;
            chatListBox->AppendText(date + "\n");
            //chatListBox->AppendText("                                                       " + this->date + "\n");

        }
       
        while (enumerator->MoveNext()) {
            ChatMessage^ chatMessage = enumerator->Current;
            int start = chatListBox->TextLength;
            String^ message = chatMessage->getMessage();
            String^ date2 = ConvertDate(chatMessage->getTimestamp());
            String^ date3 = ConvertHour(chatMessage->getTimestamp());
            if (chatMessage->getMessage()->Length > 15) message = FormatMessage(chatMessage->getMessage());

            if (*chatMessage->getUserId() != *id_user) {
                if (this->date != date2) {
                    this->date = date2;
                    chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Italic);
                    chatListBox->SelectionAlignment = HorizontalAlignment::Center;
                    chatListBox->AppendText(this->date+"\n");
                    //chatListBox->AppendText(this->date + "                                                       " + "\n");
                }
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->SelectionAlignment = HorizontalAlignment::Left;
                chatListBox->AppendText(chatMessage->getUsername() + " ["+ date3 +"]: ");
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                chatListBox->AppendText(message + "\n");
            }
            else {
                if (this->date != date2) {
                    this->date = date2;
                    chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Italic);
                    chatListBox->SelectionAlignment = HorizontalAlignment::Center;
                    chatListBox->AppendText(this->date + "\n");
                   // chatListBox->AppendText(this->date + "                                                       " + "\n");
                }
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->SelectionAlignment = HorizontalAlignment::Right;
                chatListBox->AppendText("Tú [" + date3 + "]: ");
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                chatListBox->AppendText(message + "\n");
            }

            int length = chatListBox->TextLength - start;
            chatListBox->Select(start, length);
            
            /*if (*chatMessage->getUserId() != *id_user) {
                chatListBox->SelectionAlignment = HorizontalAlignment::Left;
            }
            else {
                chatListBox->SelectionAlignment = HorizontalAlignment::Right;
            }*/
        
                chatListBox->SelectionCharOffset = 5;
                chatListBox->SelectionStart = chatListBox->TextLength;
                chatListBox->ScrollToCaret();
                lastMessage = chatMessage;
            }

            if (lastMessage != nullptr) {
                messagelast_id = lastMessage->getId();
            }
        }
    
    System::String^ ChatGrupEstudiUI::FormatMessage(System::String^ message) {
        int maxLineLength = 35;  // Límite de caracteres antes de intentar un salto de línea
        for (int i = maxLineLength; i < message->Length; i += maxLineLength) {
            // Busca el espacio más cercano a la izquierda desde la posición i
            int spacePos = message->LastIndexOf(' ', i);
            if (spacePos != -1 && spacePos > i - maxLineLength) {
                message = message->Insert(spacePos + 1, "\n");
                i = spacePos + 1; // ajusta i para continuar desde el nuevo salto de línea
            }
            else {
                // No se encontró un espacio adecuado, busca hacia adelante para el próximo espacio
                int forwardSpacePos = message->IndexOf(' ', i);
                if (forwardSpacePos != -1) {
                    message = message->Insert(forwardSpacePos + 1, "\n");
                    i = forwardSpacePos + 1; // ajusta i para continuar desde el nuevo salto de línea
                }
            }
        }
        return message;
    }
    

    Void ChatGrupEstudiUI::ChatGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e) {
        Int64^ user_id = CurrentSession::Instance->GetCurrentUser()->GetUserId();
        chatMembers_Refresh = chatGrupEstudiService->CheckLastsMessage(id_group, user_id, messagelast_id);
        
        if (chatMembers_Refresh->Count > 0) 
        {
            ChatMessage^ lastMessage = nullptr;

			System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers_Refresh->GetEnumerator();
            while (enumerator->MoveNext()) {
				ChatMessage^ chatMessage = enumerator->Current;
                if (this->date != ConvertDate(chatMessage->getTimestamp())) {
					this->date = ConvertDate(chatMessage->getTimestamp());
					chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Italic);
					chatListBox->SelectionAlignment = HorizontalAlignment::Center;
					chatListBox->AppendText(this->date + "\n");
				}
                int start = chatListBox->TextLength;
                String^ message = FormatMessage(chatMessage->getMessage());
                String^ date3 = ConvertHour(chatMessage->getTimestamp());
                if (chatMessage->getMessage()->Length > 50) message = FormatMessage(chatMessage->getMessage());
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->AppendText(chatMessage->getUsername() + " [" + date3 + "]: ");
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                chatListBox->AppendText(message + "\n");
                int length = chatListBox->TextLength - start;
                chatListBox->Select(start, length);
                chatListBox->SelectionAlignment = HorizontalAlignment::Left;
                chatListBox->SelectionCharOffset = 5;
                chatListBox->SelectionStart = chatListBox->TextLength;
                chatListBox->ScrollToCaret();
                lastMessage = chatMessage;
			}
            if (lastMessage != nullptr)
            {
                messagelast_id = lastMessage->getId();
            }
            chatMembers_Refresh->Clear();
		}
        
	}

    System::Void ChatGrupEstudiUI::FilesGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e)
    {
		List<Files^>^ files_refresh = chatGrupEstudiService->CheckLastsFiles(id_group, last_file_id);

		if (files_refresh->Count > 0) 
        {
			System::Collections::Generic::IEnumerator<Files^>^ enumerator = files_refresh->GetEnumerator();
            while (enumerator->MoveNext()) {

				files->Add(enumerator->Current);
				listBoxFiles->Items->Add(enumerator->Current->get_filename() + enumerator->Current->get_file_type());
                
                last_file_id = enumerator->Current->get_id();
			}
			files_refresh->Clear();
		}
        
    }

    System::Void ChatGrupEstudiUI::Button_Cancelar_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->chatTimer->Stop();
        GrupEstudi_InfoUI^ PanelUI = gcnew GrupEstudi_InfoUI(group->GetGroupName(), 1);

        PanelUI->TopLevel = false;
        PanelUI->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        PanelUI->Dock = System::Windows::Forms::DockStyle::Fill;

        MainPageUI::Instance->screen->Controls->Clear();
        MainPageUI::Instance->screen->Controls->Add(PanelUI);
        PanelUI->Show();
    }
    System::Void ChatGrupEstudiUI::Button_Send_Files_Click(System::Object^ sender, System::EventArgs^ e)
    {
        OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
        openFileDialog->InitialDirectory = "c:\\";
        openFileDialog->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
        openFileDialog->FilterIndex = 2;
        openFileDialog->RestoreDirectory = true;

        if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            String^ filePath = openFileDialog->FileName;
            String^ fileName = Path::GetFileNameWithoutExtension(filePath);
            String^ fileType = Path::GetExtension(filePath);
            array<Byte>^ fileData = fileByteConverterService->FileToBytes(filePath);
            if (fileData != nullptr) {
                bool check = chatGrupEstudiService->SendFile(id_group, CurrentSession::Instance->GetCurrentUser()->GetUserId(), fileName, fileType, fileData);
                if (check == true) {
                    MessageManager::InfoMessage("Fitxer emmagatzemat correctament.");
                    files->Clear();
                    listBoxFiles->Items->Clear();
                    LoadFiles();
                }
                else MessageManager::ErrorMessage("Error al enviar el fitxer.");
            }
			else {
				MessageManager::ErrorMessage("Error al convertir el fitxer a bytes.");
			}
        }
    }
    Void ChatGrupEstudiUI::Button_DownloadFile_Click(System::Object^ sender, System::EventArgs^ e)
    {
       
        if (listBoxFiles->SelectedIndex == -1)
        {
			MessageManager::ErrorMessage("Seleccioni un fitxer per descargar.");
			return;
		}
        else {
            int select_index = listBoxFiles->SelectedIndex;
            System::Collections::Generic::IEnumerator<Files^>^ enumerator = files->GetEnumerator();
            int i = 0;
            Files^ file = nullptr;
            while (enumerator->MoveNext()) {
                if (i == select_index) {
                    file = enumerator->Current;
                    break;
                }
                i++;
            }

            array<Byte>^ file_content = file->get_file_content();
            if (file_content != nullptr) {
                SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
                String^ fileType = file->get_file_type();
                String ^ name = file->get_filename();
               
                saveFileDialog->Filter = "Specific files (*" + fileType + ")|*" + fileType + "|All files (*.*)|*.*";
                saveFileDialog->FilterIndex = 1; 
                saveFileDialog->Title = "Guardar archivo";
                String^ defaultExt = fileType->TrimStart('.'); 
                saveFileDialog->DefaultExt = defaultExt;
                
                saveFileDialog->FileName = name;

                if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    String^ filePath = saveFileDialog->FileName;
                    FileStream^ fs = gcnew FileStream(filePath, FileMode::Create);
                    BinaryWriter^ bw = gcnew BinaryWriter(fs);
                    bw->Write(file_content);
                    bw->Close();
                    fs->Close();
                    MessageManager::InfoMessage("Archivo guardado con éxito.");
                }
                else {
                    MessageManager::ErrorMessage("Error al descargar el archivo.");
                }
            }
        }
       
    }

    Void ChatGrupEstudiUI::LoadFiles()
    {
        
        files = chatGrupEstudiService->GetFiles(id_group);
        System::Collections::Generic::IEnumerator<Files^>^ enumerator = files->GetEnumerator();
        while (enumerator->MoveNext()) {
			Files^ file = enumerator->Current;
			listBoxFiles->Items->Add(file->get_filename()+file->get_file_type());
			last_file_id = file->get_id();
		}
    }  

    String^ ChatGrupEstudiUI::ConvertDate(DateTime^ date) {
		
        // I have a date = 2024-05-26 15:06:39 , write me a function that returns the date 26 May 2024
        
        String^ month = date->ToString("MMMM");
        String^ day = date->ToString("dd");
        String^ year = date->ToString("yyyy");
        // month is 06 write me a function that returns May in Spanish
        if (month == "January") month = "Enero";
        if (month == "February") month = "Febrero";
        if (month == "March") month = "Marzo";
        if (month == "April") month = "Abril";
        if (month == "May") month = "Mayo";
        if (month == "June") month = "Junio";
        if (month == "July") month = "Julio";
        if (month == "August") month = "Agosto";
        if (month == "September") month = "Septiembre";
        if (month == "October") month = "Octubre";
        if (month == "November") month = "Noviembre";
        if (month == "December") month = "Diciembre";
        
        return (day + " " + month + " " + year);
	}
    String^ ChatGrupEstudiUI::ConvertHour(DateTime^ date) {
		String^ hour = date->ToString("HH");
		String^ minute = date->ToString("mm");
		return (hour + ":" + minute);
	}
}

