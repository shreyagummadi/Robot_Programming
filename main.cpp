#include <iostream>
#include <array>
#include <vector>
#include <string>
int main()
{
    
std::cout<<"Declaring and initializing a 2D array of std::string"<<std::endl;

std::array<std::array<std::string,2>,3> string_arr = {{{ "blue","white"},
                                                {"green","white"},
                                                {"green","white"}}};
                                                
std::cout<<"Finished Declaring 2D array"<<std::endl;

std::cout<<"*********************************************************"<<std::endl;
                                                
std::cout<<"Declaring and initializing three string vectors"<<std::endl;

std::vector<std::string> color_vec1{string_arr[0][0],string_arr[0][1]};
std::vector<std::string> color_vec2{string_arr[1][0],string_arr[1][1]};
std::vector<std::string> color_vec3{string_arr[2][0],string_arr[2][1]};

std::cout<<"Please the three colors for the missing pegs(green,white,blue)"<<std::endl;
std::string color_1;                     //green
std::string color_2;                     // white
std::string color_3;                     // blue
std::cin >>  color_1 >> color_2 >> color_3;
color_vec1.push_back(color_1);
std::cout<<"Vector 1 :"<<" "<< color_vec1[0]<<" " << color_vec1[1]<<" " << color_vec1[2]<<std::endl;
color_vec2.insert(color_vec2.begin(),color_2);
std::cout<<"Vector 2 :"<<" "<< color_vec2[0]<<" " << color_vec2[1]<<" " << color_vec2[2]<<std::endl;
color_vec3.insert(color_vec3.begin()+1,color_3);
std::cout<<"Vector 3 :"<<" "<< color_vec3[0]<<" " << color_vec3[1]<<" " << color_vec3[2]<<std::endl;


std::cout<<"Create a 2d vector"<<std::endl;
//std::vector<std::vector<std::string,3>,3> color_vec_2d {{{color_vec1[0],color_vec1[1],color_vec1[2]},
                                                       // {color_vec2[0],color_vec2[1],color_vec2[2]},
                                                        //{color_vec3[0],color_vec3[1],color_vec3[2]}}}

}