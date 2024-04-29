#include "pch.h"
#include "CaptchaUI.h"
#include "StartPageUI.h"
#include <random>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Text;

namespace CppCLRWinFormsProject {

    String^ CaptchaUI::GenerateRandomText(int length)
    {
        vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                     'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                     '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        StringBuilder^ result = gcnew StringBuilder(length);
        Random^ rand = gcnew Random((int)DateTime::Now.Ticks);
        //String^ result = "";
        for (int i = 0; i < length; i++)
        {
            int index = rand->Next(chars.size());
            char selectedChar = chars[index];
            result->Append(Convert::ToChar(selectedChar)); // Convierte explícitamente a Char
        }
        return result->ToString();
    }



    void CaptchaUI::GenerateCaptcha()
    {
        String^ captchaText = GenerateRandomText(6);
        Bitmap^ image = gcnew Bitmap(358, 100);
        Graphics^ g = Graphics::FromImage(image);
        g->Clear(Color::White);
        Random^ rand = gcnew Random((int)DateTime::Now.Ticks);


        int fontSize = 20; 
        SizeF textSize;
        do
        {
            delete MyFont; 
            MyFont = gcnew System::Drawing::Font("Times New Roman", fontSize, FontStyle::Bold);
            textSize = g->MeasureString(captchaText, MyFont);
            fontSize--;
        } while (textSize.Width > image->Width && fontSize > 10);

        for (int i = 0; i < 1000; i++)
        {
            int x1 = rand->Next(image->Width);
            int y1 = rand->Next(image->Height);
            int x2 = rand->Next(image->Width);
            int y2 = rand->Next(image->Height);
            g->DrawLine(Pens::Gray, x1, y1, x2, y2);
        }

        g->TranslateTransform((image->Width - textSize.Width) / 2, (image->Height - textSize.Height) / 2);
        g->RotateTransform(rand->Next(-30, 30)); 
        // Color
        g->DrawString(captchaText, MyFont, Brushes::DarkSlateGray, PointF(0, 0));

        for (int i = 0; i < 5000; i++)
        {
            int x = rand->Next(image->Width);
            int y = rand->Next(image->Height);
            image->SetPixel(x, y, Color::FromArgb(rand->Next(256), rand->Next(256), rand->Next(256)));
        }

        pictureBox1->Image = image;
        textBox1->Tag = captchaText; 
    }

    void CaptchaUI::VerifyCaptcha()
    {
        if (textBox1->Text->Equals(textBox1->Tag->ToString()))
        {
            this->Hide();
            StartPageUI::Instance->captcha_ok = true;
            this->Close();
        }
        else
        {
            MessageManager::WarningMessage("Captcha incorrecte. Si us plau, torna-ho a intentar!");
        }
    }

    Void CaptchaUI::Cancelar_Click(System::Object^ sender, System::EventArgs^ e) 
    {
		this->Hide();
		this->Close();
	}

}