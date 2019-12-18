#include "gtest/gtest.h"
#include "src/utilities/include/uid_numeric.h"
#include "src/utilities/include/uid_alphanumeric.h"

using namespace banking_lib_utilities;
using namespace std;
TEST(UIDShould, ReturnRandomUid){
    
    string iPool = "uid_test_int";
    string sPool = "uid_test_string";
    auto uid_int_pool_created = UIDNumeric::create_UIDPool(iPool);

    ASSERT_EQ(uid_int_pool_created, true);

    auto uid1 = UIDNumeric::get_new_uid(iPool);
    auto uid2 = UIDNumeric::get_new_uid(iPool);
    cout<<"uid1 = "<<uid1<<endl;
    cout<<"uid2 = "<<uid2<<endl;

    EXPECT_NE(uid1, uid2);

    auto uid_str_pool_created = UIDAlphaNumeric::create_UIDPool(sPool);

    ASSERT_EQ(uid_str_pool_created, true);

    auto uid1_s = UIDAlphaNumeric::get_new_uid(sPool);
    auto uid2_s = UIDAlphaNumeric::get_new_uid(sPool);

    cout<<"uid1_s = "<<uid1_s<<endl;
    cout<<"uid2_s = "<<uid2_s<<endl;
    
    EXPECT_NE(uid1_s, uid2_s);
}


TEST(UIDShould, GetAllAvailablePools){
    string iPool = "uid_test_int";
    string sPool = "uid_test_string";

    auto uid_int_pool_created = UIDNumeric::create_UIDPool(iPool);
    auto uid_str_pool_created = UIDAlphaNumeric::create_UIDPool(sPool);

    ASSERT_EQ(uid_str_pool_created, true);
    ASSERT_EQ(uid_int_pool_created, true);

    
    list<string> str_pool_name = UIDAlphaNumeric::get_available_uid_pool();
    ASSERT_NE(str_pool_name.empty(), true);
    cout<<"string based pool names"<<endl;
    for (auto v : str_pool_name) {
        cout<< v << "\n";
    }

    list<string> int_pool_name = UIDNumeric::get_available_uid_pool();
    cout<<"int64_t based pool names"<<endl;
    ASSERT_NE(int_pool_name.empty(), true);
    for (auto v : int_pool_name) {
        cout<< v << "\n";
    }
}

TEST(UIDShould, RemoveWhenReleased) {
    string iPool = "uid_test_int";
    string sPool = "uid_test_string";

    auto uid_int_pool_created = UIDNumeric::create_UIDPool(iPool);
    auto uid_str_pool_created = UIDAlphaNumeric::create_UIDPool(sPool);

    ASSERT_EQ(uid_str_pool_created, true);
    ASSERT_EQ(uid_int_pool_created, true);

    auto uid1 = UIDNumeric::get_new_uid(iPool);
    auto uid2 = UIDNumeric::get_new_uid(iPool);
    cout<<"uid1 = "<<uid1<<endl;
    cout<<"uid2 = "<<uid2<<endl;
    EXPECT_NE(uid1, uid2);
    auto alloc_int_ids = UIDNumeric::get_all_allocated_uid(iPool);
    cout<<"int64_t allocated ids"<<endl;
    for (auto v : alloc_int_ids) {
        cout<< v << "\n";
    }
    UIDNumeric::release_uid(iPool,uid1);

    auto alloc_int_ids_new = UIDNumeric::get_all_allocated_uid(iPool);
    cout<<"int64_t allocated ids after release"<<endl;
    for (auto v : alloc_int_ids_new) {
        cout<< v << "\n";
    }
    auto find_it = find(alloc_int_ids_new.begin(), alloc_int_ids_new.end(), uid1);
    EXPECT_EQ(find_it, alloc_int_ids_new.end());

    auto find_it2 = find(alloc_int_ids_new.begin(), alloc_int_ids_new.end(), uid2);
    EXPECT_NE(find_it2, alloc_int_ids_new.end());
    
    

    auto uid1_s = UIDAlphaNumeric::get_new_uid(sPool);
    auto uid2_s = UIDAlphaNumeric::get_new_uid(sPool);
    cout<<"uid1_s = "<<uid1_s<<endl;
    cout<<"uid2_s = "<<uid2_s<<endl;
    
    EXPECT_NE(uid1_s, uid2_s);

    auto alloc_str_ids = UIDAlphaNumeric::get_all_allocated_uid(sPool);
    cout<<"string allocated ids"<<endl;
    for (auto v : alloc_str_ids) {
        cout<< v << "\n";
    }
    UIDAlphaNumeric::release_uid(sPool, uid1_s);

    auto alloc_str_ids_new = UIDAlphaNumeric::get_all_allocated_uid(sPool);
    cout<<"str allocated ids after release"<<endl;
    for (auto v : alloc_str_ids_new) {
        cout<< v << "\n";
    }
    auto find_it_s = find(alloc_str_ids_new.begin(), alloc_str_ids_new.end(), uid1_s);
    EXPECT_EQ(find_it_s, alloc_str_ids_new.end());

    auto find_it2_s = find(alloc_str_ids_new.begin(), alloc_str_ids_new.end(), uid2_s);
    EXPECT_NE(find_it2_s, alloc_str_ids_new.end());
}