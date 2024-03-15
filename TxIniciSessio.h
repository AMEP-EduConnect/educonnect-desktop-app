#pragma once
#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
public ref class TxIniciSessio
{
public:
	TxIniciSessio();
	//Usuari^ GetUsuariById(Int64^ id);
	Usuari^ GetUsuariByPassUser(String^ username, String^ password);
	bool CheckUsername(String^ username, String^ password);
	bool CheckPassword(Usuari^ checkuser, String^ password);

private:
	UsuariRepository^ usuariRepository;
};