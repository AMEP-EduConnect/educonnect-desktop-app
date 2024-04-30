#include "pch.h"
#include "ChatGrupEstudiUI.h"
#include "GrupEstudi.h"
#include "ChatGrupEstudiService.h"
#include "MessageManager.h"
#include <string>
using namespace System;
using namespace System::Windows::Forms;
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
                chatListBox->AppendText("Tú: " + message + "\n");
                int length = chatListBox->TextLength - start;  
                chatListBox->Select(start, length);
                chatListBox->SelectionAlignment = HorizontalAlignment::Right;
                messageTextBox->Clear();
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
            if(chatMessage->getMessage()->Length > 50) message = FormatMessage(chatMessage->getMessage());
            if (*chatMessage->getUserId() != *id_user) chatListBox->AppendText(chatGrupEstudiService->GetUsernameMessageById(chatMessage->getUserId()) + ": " + message + "\n");
            else chatListBox->AppendText("Tú: " + message + "\n");
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
                chatListBox->AppendText(chatGrupEstudiService->GetUsernameMessageById(chatMessage->getUserId()) + ": " + message + "\n");
                int length = chatListBox->TextLength - start;
                chatListBox->Select(start, length);
                chatListBox->SelectionAlignment = HorizontalAlignment::Left;
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
}
