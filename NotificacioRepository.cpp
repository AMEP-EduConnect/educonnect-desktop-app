#include "pch.h"
#include "NotificacioRepository.h"

NotificacioRepository::NotificacioRepository()
{
    this->notificacions = gcnew List<Notificacio^>(0);
}

void NotificacioRepository::AddNotificacio(Notificacio^ notificacio)
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "INSERT INTO notifications (group_id, source_id, destination_id, role) VALUES (@group_id, @source_id, @destination_id, @role)";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@group_id", notificacio->GetGroup_id());
    params->Add("@source_id", notificacio->GetSource_id());
    params->Add("@destination_id", notificacio->GetDestination_id());
    params->Add("@role", notificacio->GetRole());
    DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    DatabaseConnector::Instance->Disconnect();
}

void NotificacioRepository::RemoveNotificacio(Int64^ id)
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "DELETE FROM notifications WHERE id = @id";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@id", id);
    DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    DatabaseConnector::Instance->Disconnect();
}

Notificacio^ NotificacioRepository::GetNotificacioById(Int64^ id)
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "SELECT * FROM notifications WHERE id = @id";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@id", id);
    MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);

    Notificacio^ notificacio = nullptr;
    if (data->Read())
    {
        notificacio = gcnew Notificacio();
        notificacio->SetId(data->GetInt64("id"));
        notificacio->SetGroup_id(data->GetInt64("group_id"));
        notificacio->SetSource_id(data->GetInt64("source_id"));
        notificacio->SetDestination_id(data->GetInt64("destination_id"));
        notificacio->SetRole(data->GetString("role"));
    }
    data->Close();
    DatabaseConnector::Instance->Disconnect();
    return notificacio;
}

List<Notificacio^>^ NotificacioRepository::GetAllNotificacions()
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "SELECT * FROM notifications";
    MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, nullptr);

    List<Notificacio^>^ notificacions = gcnew List<Notificacio^>(0);
    while (data->Read())
    {
        Notificacio^ notificacio = gcnew Notificacio();
        notificacio->SetId(data->GetInt64("id"));
        notificacio->SetGroup_id(data->GetInt64("group_id"));
        notificacio->SetSource_id(data->GetInt64("source_id"));
        notificacio->SetDestination_id(data->GetInt64("destination_id"));
        notificacio->SetRole(data->GetString("role"));
        notificacions->Add(notificacio);
    }
    data->Close();
    DatabaseConnector::Instance->Disconnect();
    return notificacions;
}

void NotificacioRepository::AcceptRequest(Int64^ id)
{
    RemoveNotificacio(id);
}

void NotificacioRepository::DenyRequest(Int64^ id)
{
    RemoveNotificacio(id);
}
