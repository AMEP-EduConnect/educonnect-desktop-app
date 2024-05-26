#pragma once
#include "gtest/gtest.h"
#include "UsuariSUT.h"

TEST(UsuariTest, GivenNewUsuariData_WhenInitialization_ThenCreateNewUser) {
    //GIVEN
    Int64^ user_id = 1LL;
    String^ username = "TestUser";
    String^ password = "TestPassword";
    String^ email = "email@email.com";
    String^ name = "TestName";
    //WHEN
    UsuariSUT^ UsuariSUT = gcnew ::UsuariSUT(user_id, username, password, email, name);
    //THEN
    ASSERT_EQ(UsuariSUT->GetUserId(), user_id);
    ASSERT_EQ(UsuariSUT->GetUsername(), username);
    ASSERT_EQ(UsuariSUT->GetPassword(), password);
    ASSERT_EQ(UsuariSUT->GetEmail(), email);
    ASSERT_EQ(UsuariSUT->GetName(), name);
}

TEST(UsuariTest, GivenExistingUsuari_WhenSetAndGet_ThenMethodsWorks) {
    // GIVEN
    UsuariSUT^ UsuariSUT = gcnew ::UsuariSUT();
    Int64^ user_id = 1LL;
    String^ username = "TestUser";
    String^ password = "TestPassword";
    String^ email = "email@email.com";
    String^ name = "TestName";
    // WHEN
    UsuariSUT->SetUserId(user_id);
    UsuariSUT->SetUsername(username);
    UsuariSUT->SetPassword(password);
    UsuariSUT->SetEmail(email);
    UsuariSUT->SetName(name);
    // THEN
    ASSERT_EQ(UsuariSUT->GetUserId(), user_id);
    ASSERT_EQ(UsuariSUT->GetUsername(), username);
    ASSERT_EQ(UsuariSUT->GetPassword(), password);
    ASSERT_EQ(UsuariSUT->GetEmail(), email);
    ASSERT_EQ(UsuariSUT->GetName(), name);
}