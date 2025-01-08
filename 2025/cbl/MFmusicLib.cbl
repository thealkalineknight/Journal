       working-storage section.
       01 word-str                 pic X(30) typedef.

       01 info-data                typedef.
         05 sname                  word-str.
         05 artist                 word-str.
         05 rating                 pic 9(2)/9(2).

       01 genre                    typedef.
         05 gname                  word-str.
         05 subgenre.
           10 subname             word-str.
           10 description          word-str.
           10 underground-flag     pic A(1).
               88 is-underground   value 'Y'.
         05 rankings.
           10 top-song             info-data.
           10 top-album            info-data.

       01 rock                  genre.

       procedure division.
           move "rock" to rock::gname
           move "prog-rock" to rock::subgenre::subname
           move "wenimetchaindasumma" to rock::rankings::top-song

           display top-song.

           stop run
           .

