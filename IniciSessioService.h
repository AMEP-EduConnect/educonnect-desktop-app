#pragma once
#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
#include "CurrentSession.h"
#include "UsuariRolRepository.h"
#include "CredentialManagementService.h"
public ref class IniciSessioService
{

public:
	IniciSessioService();
	//Usuari^ GetUsuariById(Int64^ id);
	Usuari^ GetUsuariByUser(String^ username);
	bool CheckUsername(String^ username, String^ password);
	bool CheckPassword(String^ user_password, String^ password);
	Int64^ GetUserId(String^ username);

private:
	UsuariRepository^ usuariRepository;
	UsuariRolRepository^ usuariRolRepository;
	CredentialManagementService^ credentialMagamentService;
};