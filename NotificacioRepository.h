#pragma once
#include "DatabaseConnector.h"
#include "Notificacio.h"
#pragma once
#include "Notificacio.h"
#include "DatabaseConnector.h"

ref class NotificacioRepository
{
private:
    List<Notificacio^>^ notificacions;

public:
    NotificacioRepository();
    void AddNotificacio(Notificacio^ notificacio);
    void RemoveNotificacio(Int64^ id);
    Notificacio^ GetNotificacioById(Int64^ id);
    List<Notificacio^>^ GetAllNotificacions();
    void AcceptRequest(Int64^ id);
    void DenyRequest(Int64^ id);
};
