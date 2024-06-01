#include "pch.h"
#include "NotificacioService.h"
#include "DatabaseConnector.h"
#include "MessageManager.h"

NotificacioService::NotificacioService() {
    notificacioRepository = gcnew NotificacioRepository();
}

Int64^ NotificacioService::AddNotificacio(Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id)
{
    return notificacioRepository->AddNotificacio(notification_type, status, source_grup_id, source_user_id, destination_user_id);
}

void NotificacioService::RemoveNotificacio(Int64^ id) {
    notificacioRepository->RemoveNotificacio(id);
}

List<Notificacio^>^ NotificacioService::ListNotificacions(Int64^ id_current_user) {
    List<Notificacio^>^ notificacions = gcnew List<Notificacio^>(0);
    notificacions = notificacioRepository->GetNotificacionsByDestinationId(id_current_user);
    return notificacions;
}

bool NotificacioService::CheckIfInvitationExists(Int64^ source_grup_id, Int64^ destination_user_id)
{
    return notificacioRepository->CheckIfInvitationExists(source_grup_id, destination_user_id);
}

bool NotificacioService::CheckIfRequestExists(Int64^ source_grup_id, Int64^ source_user_id)
{
    return notificacioRepository->CheckIfRequestExists(source_grup_id, source_user_id);
}


void NotificacioService::ChangeStatus(Int64^ status, Notificacio^ notificacio)
{
    notificacioRepository->ChangeStatus(status, notificacio);
}

Notificacio^ NotificacioService::GetNotificacioById(Int64^ selectedId) {
    Notificacio^ notificacio = notificacioRepository->GetNotificacioById(selectedId);
    return notificacio;
}