#pragma once
#include "NotificacioRepository.h"
#include "DatabaseConnector.h"
#include <vector>
#include "Notificacio.h"

public ref class NotificacioService
{
public:
    NotificacioService();
    Int64^ AddNotificacio(Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id);
    void RemoveNotificacio(Int64^ id);
    List<Notificacio^>^ ListNotificacions(Int64^ id_current_user);
    void ChangeStatus(Int64^ status, Notificacio^ notificacio);
    Notificacio^ GetNotificacioById(Int64^ selectedId);
    bool CheckIfInvitationExists(Int64^ source_grup_id, Int64^ destination_user_id);
    bool CheckIfRequestExists(Int64^ source_grup_id, Int64^ source_user_id);

private:
    NotificacioRepository^ notificacioRepository;  
};
