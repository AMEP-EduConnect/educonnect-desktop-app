#include "pch.h"
#include "PerfilPersonalConsultaService.h"


PerfilPersonalConsultaService::PerfilPersonalConsultaService()
{
	usuariRepository = gcnew UsuariRepository();
}

Usuari^ PerfilPersonalConsultaService::GetCurrentUser()
{
	Usuari^ currentUser = CurrentSession::Instance->GetCurrentUser();
	return currentUser;
}

List<AcademicTag^>^ PerfilPersonalConsultaService::GetAcademicTagsByUserId(Int64^ user_id)
{
	return academicTagRepository->GetAcademicTagsByUserId(user_id);
}

List<AcademicTag^>^ PerfilPersonalConsultaService::GetAllAcademicTags()
{
	return academicTagRepository->GetAllAcademicTags();
}

AcademicTag^ PerfilPersonalConsultaService::GetAcademicTagByName(String^ tag_name)
{
	return academicTagRepository->GetAcademicTagByName(tag_name);
}
