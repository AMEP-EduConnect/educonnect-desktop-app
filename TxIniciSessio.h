#pragma once
#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
#include "CurrentSession.h"
public ref class TxIniciSessio
{

public:
	TxIniciSessio();
	//Usuari^ GetUsuariById(Int64^ id);
	Usuari^ GetUsuariByPassUser(String^ username, String^ password);
	bool CheckUsername(String^ username, String^ password);
	bool CheckPassword(Usuari^ checkuser, String^ password);
	Int64^ GetUserId(String^ username);

private:
	UsuariRepository^ usuariRepository;

};