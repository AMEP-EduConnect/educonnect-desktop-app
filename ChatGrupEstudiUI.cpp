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
            if(chatGrupEstudiService->SendMenssage(94LL, CurrentSession::Instance->GetCurrentUser()->GetUserId(), message) == false)
			{
				MessageManager::WarningMessage("Error al enviar el mensaje");
			}
            else 
            {
                int start = chatListBox->TextLength;  
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->AppendText("Tú: ");
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                chatListBox->AppendText(message + "\n");
                int length = chatListBox->TextLength - start;  
                chatListBox->Select(start, length);
                chatListBox->SelectionAlignment = HorizontalAlignment::Right;
                messageTextBox->Clear();
                chatListBox->SelectionCharOffset = 5;
                chatListBox->SelectionStart = chatListBox->TextLength;
                chatListBox->ScrollToCaret();
            }
        }
    }
    /*Void ChatGrupEstudiUI::ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e) {
        //String^ user = CurrentSession::Instance->GetCurrentUser()->GetUsername();
        List<ChatMessage^>^ chatMembers = chatGrupEstudiService->GetChatMembers(94LL);
        Int64^ id_user = CurrentSession::Instance->GetCurrentUser()->GetUserId();
        //chatMembers->Reverse();
        System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers->GetEnumerator();
        ChatMessage^ lastMessage = nullptr;
        while (enumerator->MoveNext()) {
			ChatMessage^ chatMessage = enumerator->Current;
            chatListBox->AppendText(chatMessage->getUserId() + ": " + chatMessage->getMessage() + "\n");
            if(*chatMessage->getUserId() != *id_user ) chatListBox->SelectionAlignment = HorizontalAlignment::Left;
			else chatListBox->SelectionAlignment = HorizontalAlignment::Right;
            lastMessage = chatMessage;
		}
        if (lastMessage != nullptr)
        {
			messagelast_id = lastMessage->getId();
		}
	}*/
    Void ChatGrupEstudiUI::ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e) {
        List<ChatMessage^>^ chatMembers = chatGrupEstudiService->GetChatMembers(94LL);
        Int64^ id_user = CurrentSession::Instance->GetCurrentUser()->GetUserId();

        System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers->GetEnumerator();
        ChatMessage^ lastMessage = nullptr;
        while (enumerator->MoveNext()) {
            ChatMessage^ chatMessage = enumerator->Current;
            int start = chatListBox->TextLength;
            String^ message = FormatMessage(chatMessage->getMessage());
            if (chatMessage->getMessage()->Length > 50) message = FormatMessage(chatMessage->getMessage());

            if (*chatMessage->getUserId() != *id_user) {
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->AppendText(chatMessage->getUsername() + ": ");
                    chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                    chatListBox->AppendText(message + "\n");
            }
            else {
                // Aplicar negrita solo a "Tú:"
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->AppendText("Tú: ");
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Regular);
                chatListBox->AppendText(message + "\n");
            }

            int length = chatListBox->TextLength - start;
            chatListBox->Select(start, length);
            if (*chatMessage->getUserId() != *id_user) {
                chatListBox->SelectionAlignment = HorizontalAlignment::Left;
            }
            else {
                chatListBox->SelectionAlignment = HorizontalAlignment::Right;
            }
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
        int maxLineLength = 43;  // Límite de caracteres antes de intentar un salto de línea
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
        chatMembers_Refresh = chatGrupEstudiService->CheckLastsMessage(94LL, user_id, messagelast_id);
        
        if (chatMembers_Refresh->Count > 0)
        {
            ChatMessage^ lastMessage = nullptr;

			System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers_Refresh->GetEnumerator();
            while (enumerator->MoveNext()) {
				ChatMessage^ chatMessage = enumerator->Current;
                int start = chatListBox->TextLength;
                String^ message = FormatMessage(chatMessage->getMessage());
                if (chatMessage->getMessage()->Length > 50) message = FormatMessage(chatMessage->getMessage());
                chatListBox->SelectionFont = gcnew System::Drawing::Font(chatListBox->Font, FontStyle::Bold);
                chatListBox->AppendText(chatMessage->getUsername() + ": ");
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
                bool check = chatGrupEstudiService->SendFile(94LL, CurrentSession::Instance->GetCurrentUser()->GetUserId(), fileName, fileType, fileData);
                if (check == true) {
                    MessageManager::InfoMessage("Archivo almacenado en la base de datos.");
                    files->Clear();
                    listBoxFiles->Items->Clear();
                    LoadFiles();
                }
                else MessageManager::ErrorMessage("Error al enviar el archivo.");
            }
			else {
				MessageManager::ErrorMessage("Error al convertir el archivo a bytes.");
			}
        }
    }
    Void ChatGrupEstudiUI::Button_DownloadFile_Click(System::Object^ sender, System::EventArgs^ e)
    {
       
        if (listBoxFiles->SelectedIndex == -1)
        {
			MessageManager::ErrorMessage("Seleccione un archivo para descargar.");
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
        
        files = chatGrupEstudiService->GetFiles(94LL);
        System::Collections::Generic::IEnumerator<Files^>^ enumerator = files->GetEnumerator();
        while (enumerator->MoveNext()) {
			Files^ file = enumerator->Current;
			listBoxFiles->Items->Add(file->get_filename()+file->get_file_type());
		}
    }



    
}

