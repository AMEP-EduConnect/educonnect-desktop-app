#pragma once
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "UsuariRepository.h"
#include "Usuari.h"
#include "AcademicTagRepository.h"
#include "AcademicTag.h"

public ref class PerfilPersonalModificaService
{
public:
	PerfilPersonalModificaService();

	bool ModificaUsuari(String^ username, String^ password, String^ email, String^ nom);
	bool CheckUsername(String^ username);
	bool CheckEmail(String^ email);
	bool addAcademicTag(Int64^ tag_id);
	bool deleteAcademicTag(Int64^ tag_id);
	

private:
	UsuariRepository^ usuariRepository;
	AcademicTagRepository^ AcademicTagRepository;
};