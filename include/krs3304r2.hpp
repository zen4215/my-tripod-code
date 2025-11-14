#pragma once

#include <IcsHardSerialClass.h>

class KRS3304R2 {
    public:
    KRS3304R2(IcsHardSerialClass& ics, int id);
    
    private:
    IcsHardSerialClass m_ics;
    int m_id;
};

KRS3304R2::KRS3304R2(IcsHardSerialClass& ics, int id) :
    m_ics(ics),
    m_id(id)
{
    
}
