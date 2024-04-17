#pragma once
#include "pch.h"
#include "UsuariRepository.h"
#include "DatabaseConnector.h"
#include "Usuari.h"
#include "CurrentSession.h"
#include "UsuariRolRepository.h"
public ref class IniciSessioService
{

public:
	IniciSessioService();
	//Usuari^ GetUsuariById(Int64^ id);
	Usuari^ GetUsuariByPassUser(String^ username, String^ password);
	bool CheckUsername(String^ username, String^ password);
	bool CheckPassword(Usuari^ checkuser, String^ password);
	Int64^ GetUserId(String^ username);

private:
	UsuariRepository^ usuariRepository;
	UsuariRolRepository^ usuariRolRepository;
};