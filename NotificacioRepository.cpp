#include "pch.h"
#include "NotificacioRepository.h"

NotificacioRepository::NotificacioRepository()
{
    this->notificacions = gcnew List<Notificacio^>(0);
}


Int64^ NotificacioRepository::AddNotificacio(Int64^ notification_type, Int64^ status, Int64^ source_grup_id, Int64^ source_user_id, Int64^ destination_user_id)
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "INSERT INTO userNotifications (notification_type, status, source_group_id, source_user_id, destination_user_id) VALUES (@notification_type, @status, @source_group_id, @source_user_id, @destination_user_id)";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@notification_type", notification_type);
    params->Add("@status", status);
    params->Add("@source_group_id", source_grup_id);
    params->Add("@source_user_id", source_user_id);
    params->Add("@destination_user_id", destination_user_id);
    MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    bool check = false;
    data->Close();
    sql = "SELECT LAST_INSERT_ID();";
    MySqlDataReader^ data2 = DatabaseConnector::Instance->ExecuteInternCommand(sql);
    Int64^ id;
    while (data2->Read()) {
        id = data2->GetInt64(0);
    }
    data2->Close();
    DatabaseConnector::Instance->Disconnect();
    return id;
}

void NotificacioRepository::RemoveNotificacio(Int64^ id)
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "DELETE FROM userNotifications WHERE id = @id";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@id", id);
    DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    DatabaseConnector::Instance->Disconnect();
}


List<Notificacio^>^ NotificacioRepository::GetNotificacionsByDestinationId(Int64^ destination_user_id, Int64^ notification_type, Int64^ status)
{
    DatabaseConnector::Instance->Connect();
    String^ sql = "SELECT * FROM userNotifications WHERE destination_user_id = @destination_user_id, notification_type = @notification_type AND status = @status ORDER BY created_at DESC";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@destination_user_id", destination_user_id);
    params->Add("@notification_type", notification_type);
    params->Add("@status", status);
    MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    List<Notificacio^>^ notificacions = gcnew List<Notificacio^>(0);
    while (data->Read())
    {
        Notificacio^ notificacio = gcnew Notificacio();
        notificacio->SetId(data->GetInt64(0));
        notificacio->SetNotificationType(data->GetInt64(1));
        notificacio->SetStatusType(data->GetInt64(2));
        notificacio->SetSourceGroupId(data->GetInt64(3));
        notificacio->SetDestinationUserId(data->GetInt64(4));
        notificacions->Add(notificacio);
    }
    data->Close();
    DatabaseConnector::Instance->Disconnect();
    return notificacions;
}



void NotificacioRepository::ChangeStatus(Int64^ status, Notificacio^ notificacio)
{
    Int64^ id = notificacio->GetId();
    DatabaseConnector::Instance->Connect();
    String^ sql = "UPDATE userNotifications SET status=@status WHERE id=@id";
    Dictionary<String^, Object^>^ params = gcnew Dictionary<String^, Object^>(0);
    params->Add("@Status", status);
    MySqlDataReader^ data = DatabaseConnector::Instance->ExecuteClientCommand(sql, params);
    data->Close();
    DatabaseConnector::Instance->Disconnect();
    notificacio->SetStatusType(status);
    return;
}

