// C/C++ File

// Author:   Alexandre Tea <alexandre.qtea@gmail.com>
// File:     /Users/alexandretea/Work/concepts/search/gridland_metro/gridland_metro.cpp
// Purpose:  TODO (a one-line explanation)
// Created:  2017-06-16 17:27:54
// Modified: 2017-06-16 18:36:28

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct Track
{
	long long	start;
	long long	end;

    bool
    operator<(Track const& other) const
    {
        return start < other.start;
    }
};

typedef std::unordered_map<long long, std::vector<Track>>    TrackBook;

struct MetroMap
{
	long long	nb_rows;
	long long 	nb_columns;
	long long 	nb_tracks;

	TrackBook		tracks;
};

static long long
count_track_cells(TrackBook& tracks)
{
    long long count = 0;

    for (auto& row: tracks) {
        std::sort(row.second.begin(), row.second.end());

        Track   merged = row.second.front();

        for (long long i = 1; i < row.second.size(); ++i) {
            //std::cout << row.second[i].start << " <= " << merged.end << std::endl;
            if (row.second[i].start <= merged.end) {
                merged.end = std::max(merged.end, row.second[i].end);
            } else {
                count += (merged.end - merged.start + 1);
                //std::cout << "add " << (merged.end - merged.start + 1) << std::endl;
                merged = row.second[i];
            }
        }
        count += merged.end - merged.start + 1;
        //std::cout << "xadd " << (merged.end - merged.start + 1) << std::endl;
    }
    return count;
}

static long long
find_nb_lampposts(MetroMap const& map)
{
    TrackBook   trackbook = map.tracks;

    return (map.nb_rows * map.nb_columns) - count_track_cells(trackbook);
}

int
main()
{
    MetroMap	map;

    std::cin >> map.nb_rows;
    std::cin >> map.nb_columns;
    std::cin >> map.nb_tracks;
    for (long long i = 0; i < map.nb_tracks; ++i) {
        long long	row;
        Track			t;

        std::cin >> row;
        std::cin >> t.start;
        std::cin >> t.end;
        map.tracks[row].push_back(t);
    }
    std::cout << find_nb_lampposts(map) << std::endl;
    return 0;
}
