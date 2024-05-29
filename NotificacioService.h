#pragma once
#include "NotificacioRepository.h"
#include <vector>

public ref class NotificacioService
{
public:
    NotificacioService();
    Int64^ AddNotificacio(Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id);
    List<Notificacio^>^ ListNotificacions(Int64^ id_destination, Int64^ type);
    void ChangeStatus(Int64^ status, Notificacio^ notificacio);
private:
    NotificacioRepository^ notificacioRepository;
  
};