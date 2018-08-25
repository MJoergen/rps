cmake_minimum_required(VERSION 3.12)
project(rps)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(rps
        main.cc
        match.cc
        match.h
        move.h
        player.h
        player_const.h
        player_copy.h
		player_random_dist.h
		player_ask.h)
