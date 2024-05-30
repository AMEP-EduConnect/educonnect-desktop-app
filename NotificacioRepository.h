#pragma once

#include "Notificacio.h"
#include "DatabaseConnector.h"

public ref class NotificacioRepository
{
private:


public:
    NotificacioRepository();

    Int64^ AddNotificacio(Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id);
    void RemoveNotificacio(Int64^ id);
    List<Notificacio^>^ GetNotificacionsByDestinationId(Int64^ id_destination, Int64^ status);
    void ChangeStatus(Int64^ status, Notificacio^ notificacio);

    Notificacio^ GetNotificacioById(Int64^ id);

};