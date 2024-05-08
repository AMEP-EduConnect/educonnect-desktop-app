#include "pch.h"
#include "GrupSessionAttendant.h"

GrupSessionAttendant::GrupSessionAttendant() {
    id = nullptr;
    idsession = nullptr;
    iduser = nullptr;
}

GrupSessionAttendant::GrupSessionAttendant(Int64^ id, Int64^ idsessions, Int64^ iduser) {
    this->id = id;
    this->idsession = idsession;
    this->iduser = iduser;
}

Int64^ GrupSessionAttendant::GetId()
{
    return id;
}

Int64^ GrupSessionAttendant::GetIdSession()
{
    return idsession;
}

Int64^ GrupSessionAttendant::GetIdUser()
{
    return iduser;
}

void GrupSessionAttendant::SetId(Int64^ id)
{
    this->id = id;
}

void GrupSessionAttendant::SetIdSession(Int64^ idsession)
{
    this->idsession = idsession;
}

void GrupSessionAttendant::SetIdUser(Int64^ iduser)
{
    this->iduser = iduser;
}
