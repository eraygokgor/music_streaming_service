#include "MusicStream.h"

#include <iostream>

void MusicStream::addProfile(const std::string &email, const std::string &username, SubscriptionPlan plan) {
    /* TODO */
    Profile newProfile(email, username, plan);
    profiles.insertAtTheEnd(newProfile);
}

void MusicStream::deleteProfile(const std::string &email) {
    /* TODO */
    Node<Profile> *p = profiles.getFirstNode();
    while(p){
        if (p->data.getEmail() == email){
            Profile *myProfile = &p->data;
            LinkedList<Profile *> followersTBD = p->data.getFollowers();
            int sizeOfFollowers = followersTBD.getSize();
            for (int i=0; i < sizeOfFollowers; i++){
                Node<Profile *> *currentFollower = followersTBD.getNodeAtIndex(i);
                currentFollower->data->unfollowProfile(myProfile);
                }
            }

            LinkedList<Profile *> followingsTBD = p->data.getFollowings();
            int sizeOfFollowings = followingsTBD.getSize();
            for (int i=0; i < sizeOfFollowings; i++){
                Node<Profile *> *currentFollower = followingsTBD.getNodeAtIndex(i);
                Profile *ufUser = currentFollower->data;
                p->data.unfollowProfile(ufUser);
            }
            profiles.removeNode(p->data);
            break;
        }
        p = p->next;
    }

void MusicStream::addArtist(const std::string &artistName) {
    /* TODO */
    Artist *newArtist = new Artist(artistName);
    artists.insertAtTheEnd(*newArtist);
}

void MusicStream::addAlbum(const std::string &albumName, int artistId) {
    /* TODO */
    Album *newAlbum = new Album(albumName);
    albums.insertAtTheEnd(*newAlbum);
    Node<Artist> *artistsp = artists.getFirstNode();
    while(artistsp){
        if (artistsp->data.getArtistId() == artistId){
            artistsp->data.addAlbum(newAlbum);
            break;
        }
        artistsp = artistsp->next;
    }
}

void MusicStream::addSong(const std::string &songName, int songDuration, int albumId) {
    /* TODO */
    Song *newSong = new Song(songName, songDuration);
    songs.insertAtTheEnd(*newSong);
    Node<Album> *albumsp = albums.getFirstNode();
    while(albumsp){
        if(albumsp->data.getAlbumId() == albumId){
            albumsp->data.addSong(newSong);
            break;
        }
        albumsp = albumsp->next;
    }

}

void MusicStream::followProfile(const std::string &email1, const std::string &email2) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email1){
            Profile *profile1 = &profilesp->data;
            Node<Profile> *profilesp = profiles.getFirstNode();
            while(profilesp){
                if(profilesp->data.getEmail() == email2){
                Profile *profile2 = &profilesp->data;
                profile1->followProfile(profile2);
                LinkedList<Profile *> p2Followers = profile2->getFollowers();
                p2Followers.insertAtTheEnd(profile2);
                break;
                }
                profilesp = profilesp->next;
            }
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::unfollowProfile(const std::string &email1, const std::string &email2) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email1){
            Profile *profile1 = &profilesp->data;
            Node<Profile> *profilesp = profiles.getFirstNode();
            while(profilesp){
                if(profilesp->data.getEmail() == email2){
                Profile *profile2 = &profilesp->data;
                profile1->unfollowProfile(profile2);
                LinkedList<Profile *> p2Followers = profile2->getFollowers();
                p2Followers.removeNode(profile2);
                break;
                profilesp = profilesp->next;
                }
            }
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::createPlaylist(const std::string &email, const std::string &playlistName) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if (profilesp->data.getEmail() == email){
            profilesp->data.createPlaylist(playlistName);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::deletePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if (profilesp->data.getEmail() == email){
            profilesp->data.deletePlaylist(playlistId);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::addSongToPlaylist(const std::string &email, int songId, int playlistId) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if (profilesp->data.getEmail() == email){
            Playlist *playlistp = profilesp->data.getPlaylist(playlistId);
            Node<Song> *songsp = songs.getFirstNode();
            while(songsp){
                if (songsp->data.getSongId() == songId){
                    playlistp->addSong(&songsp->data);
                    break;
                }
            }
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::deleteSongFromPlaylist(const std::string &email, int songId, int playlistId) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if (profilesp->data.getEmail() == email){
            Playlist *playlistp = profilesp->data.getPlaylist(playlistId);
            Node<Song> *songsp = songs.getFirstNode();
            while(songsp){
                if (songsp->data.getSongId() == songId){
                    playlistp->dropSong(&songsp->data);
                    break;
                }
            }
            break;
        }
        profilesp = profilesp->next;
    }
}

LinkedList<Song *> MusicStream::playPlaylist(const std::string &email, Playlist *playlist) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            if (profilesp->data.getPlan() == premium){
                LinkedList<Song *> playList = playlist->getSongs();
                return playList;
            }
            else{
                LinkedList<Song *> playList = playlist->getSongs();
                playList.insertAsEveryKthNode(&Song::ADVERTISEMENT_SONG, 2);
                return playList;
            }
            break;
        }
        profilesp = profilesp->next;
    }
}

Playlist *MusicStream::getPlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            return profilesp->data.getPlaylist(playlistId);
            break;
        }
        profilesp = profilesp->next;
    }  

}

LinkedList<Playlist *> MusicStream::getSharedPlaylists(const std::string &email) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            return profilesp->data.getSharedPlaylists();
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::shufflePlaylist(const std::string &email, int playlistId, int seed) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            Playlist *shuffleList = profilesp->data.getPlaylist(playlistId);
            shuffleList->shuffle(seed);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::sharePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            Playlist *shareList = profilesp->data.getPlaylist(playlistId);
            shareList->setShared(true);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::unsharePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            Playlist *shareList = profilesp->data.getPlaylist(playlistId);
            shareList->setShared(false);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::subscribePremium(const std::string &email) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            profilesp->data.setPlan(premium);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::unsubscribePremium(const std::string &email) {
    /* TODO */
    Node<Profile> *profilesp = profiles.getFirstNode();
    while(profilesp){
        if(profilesp->data.getEmail() == email){
            profilesp->data.setPlan(free_of_charge);
            break;
        }
        profilesp = profilesp->next;
    }
}

void MusicStream::print() const {
    std::cout << "# Printing the music stream ..." << std::endl;

    std::cout << "# Number of profiles is " << this->profiles.getSize() << ":" << std::endl;
    this->profiles.print();

    std::cout << "# Number of artists is " << this->artists.getSize() << ":" << std::endl;
    this->artists.print();

    std::cout << "# Number of albums is " << this->albums.getSize() << ":" << std::endl;
    this->albums.print();

    std::cout << "# Number of songs is " << this->songs.getSize() << ":" << std::endl;
    this->songs.print();

    std::cout << "# Printing is done." << std::endl;
}
