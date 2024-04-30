#include "pch.h"
#include "ChatGrupEstudiUI.h"
#include "GrupEstudi.h"
#include "ChatGrupEstudiService.h"
#include "MessageManager.h"

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
                chatListBox->Items->Add("Tú: " + message);
                messageTextBox->Clear();
            }
        }
    }
    Void ChatGrupEstudiUI::ChatGrupEstudiUI_Load(System::Object^ sender, System::EventArgs^ e) {
        //String^ user = CurrentSession::Instance->GetCurrentUser()->GetUsername();
        List<ChatMessage^>^ chatMembers = chatGrupEstudiService->GetChatMembers(94LL);
        //chatMembers->Reverse();
        System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers->GetEnumerator();
        while (enumerator->MoveNext()) {
			ChatMessage^ chatMessage = enumerator->Current;
            chatListBox->Items->Add(chatMessage->getUserId() + ": " + chatMessage->getMessage());
		}
	}
    Void ChatGrupEstudiUI::ChatGrupEstudiUI_Refresh(System::Object^ sender, System::EventArgs^ e) {
        Int64^ user_id = CurrentSession::Instance->GetCurrentUser()->GetUserId();
        chatMembers_Refresh = chatGrupEstudiService->CheckLastsMessage(94LL, user_id,DateTime::Now);
        if (chatMembers_Refresh->Count > 0)
        {
			System::Collections::Generic::IEnumerator<ChatMessage^>^ enumerator = chatMembers_Refresh->GetEnumerator();
            while (enumerator->MoveNext()) {
				ChatMessage^ chatMessage = enumerator->Current;
				chatListBox->Items->Add(chatMessage->getUserId() + ": " + chatMessage->getMessage());
			}
            chatMembers_Refresh->Clear();
		}
        
	}
}
