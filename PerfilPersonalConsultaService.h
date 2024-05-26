#pragma once
#include "UsuariRepository.h"
#include "Usuari.h"
#include "DatabaseConnector.h"
#include "CurrentSession.h"
#include "AcademicTagRepository.h"


public ref class PerfilPersonalConsultaService
{
public:
	PerfilPersonalConsultaService();

	Usuari^ GetCurrentUser();
	List<AcademicTag^>^ GetAcademicTagsByUserId(Int64^ user_id);
	List<AcademicTag^>^ GetAllAcademicTags();
	AcademicTag^ GetAcademicTagByName(String^ tag_name);

private:
	UsuariRepository^ usuariRepository;
	AcademicTagRepository^ academicTagRepository;
};