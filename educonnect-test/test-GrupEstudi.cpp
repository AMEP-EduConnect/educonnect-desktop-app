#pragma once
#include "gtest/gtest.h"
#include "GrupEstudiSUT.h"

TEST(GrupEstudiTest, GivenNewGrupData_WhenInitialization_ThenCreateNewGrup) {
    // GIVEN
    Int64^ id = 1LL;
    String^ group_name = "TestGroup";
    Int64^ group_owner_id = 123LL;
    Int64^ group_academic_tag = 456LL;
    String^ description = "Test description";

    // WHEN
	GrupEstudiSUT^ GrupEstudiSUT = gcnew ::GrupEstudiSUT(id, group_name, group_owner_id, group_academic_tag, description);

    // THEN
    ASSERT_EQ(GrupEstudiSUT->GetId(), id);
    ASSERT_EQ(GrupEstudiSUT->GetGroupName(), group_name);
    ASSERT_EQ(GrupEstudiSUT->GetGroupOwnerId(), group_owner_id);
    ASSERT_EQ(GrupEstudiSUT->GetGroupAcademicTag(), group_academic_tag);
    ASSERT_EQ(GrupEstudiSUT->GetDescription(), description);
}

TEST(GrupEstudiTest, GivenExistingGrup_WhenSetAndGet_ThenMethodsWorks) {
    // GIVEN
    GrupEstudiSUT^ GrupEstudiSUT = gcnew ::GrupEstudiSUT();
    Int64^ id = 1LL;
    String^ group_name = "TestGroup";
    Int64^ group_owner_id = 123LL;
    Int64^ group_academic_tag = 456LL;
    String^ description = "Test description";

    // WHEN
    GrupEstudiSUT->SetId(id);
    GrupEstudiSUT->SetGroupName(group_name);
    GrupEstudiSUT->SetGroupOwnerId(group_owner_id);
    GrupEstudiSUT->SetGroupAcademicTag(group_academic_tag);
    GrupEstudiSUT->SetDescription(description);

    // THEN
    ASSERT_EQ(GrupEstudiSUT->GetId(), id);
    ASSERT_EQ(GrupEstudiSUT->GetGroupName(), group_name);
    ASSERT_EQ(GrupEstudiSUT->GetGroupOwnerId(), group_owner_id);
    ASSERT_EQ(GrupEstudiSUT->GetGroupAcademicTag(), group_academic_tag);
    ASSERT_EQ(GrupEstudiSUT->GetDescription(), description);
}