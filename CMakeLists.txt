cmake_minimum_required(VERSION 3.12)
project(rps)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
include_directories(.)

add_executable(rps
        main.cc
        match.cc
        match.h
        move.h
		move.cc
		tournament.cc
		tournament.h
        player.h
		player_alternate.h
        player_copy.h
		player_random.h
		player_random_dist.h
		player_ask.h
		player_mads.h
		player_next.h
		player_next_2.h
		player_anti_next.h
		player_const.h
		player_const_2.h
		player_cycle.h
		player_cycle_2.h
		player_cycle_3.h
		player_mike.h
		player_mike_2.h
		player_mike_3.h
		player_mike_4.h
		player_anti_mike.h
		player_delay.h
		delay_2.h)
