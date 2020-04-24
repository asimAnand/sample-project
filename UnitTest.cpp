// The following needs to be added to "Open3D/src/UnitTest/TestUtility/UnitTest.cpp"

// ----------------------------------------------------------------------------
// Test equality of two nested vectors of int.
// ----------------------------------------------------------------------------
void unit_test::ExpectEQ(vector<vector<int>>& v0, vector<vector<int>>& v1) {
    EXPECT_EQ(v0.size(), v1.size());

    vector<vector<int>>::iterator outer_vector0;
    vector<vector<int>>::iterator outer_vector1;
    outer_vector0 = v0.begin();
    outer_vector1 = v1.begin();

    while(outer_vector0 != v0.end() && outer_vector1 != v1.end()){
        EXPECT_EQ((*outer_vector0).size(), (*outer_vector1).size());
        ExpectEQ((*outer_vector0).data(), (*outer_vector1).data(), (*outer_vector0).size());
        outer_vector0++;
        outer_vector1++;
    }
}

