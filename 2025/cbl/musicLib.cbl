       working-storage section.
       01  music.
           05 rock.
               15 prog-rock.
                   25 sname pic X(30).
                   25 bpm pic 9(3)/9(3).
               15 shoegaze.
                   25 sname pic X(30).
                   25 bpm pic 9(3).
               15 post-rock.
                   25 sname pic X(30).
                   25 bpm pic 9(3).
           05 metal.
               15 neoclassical.
                   25 sname pic X(30).
                   25 bpm pic 9(3).
               15 groove-metal.
                   25 sname pic X(30).
                   25 bpm pic 9(3).
               15 death-metal.
                   25 sname pic X(30).
                   25 bpm pic 9(3).
       01 top-artist pic A(12) value "Spiderguaves".

       procedure division.
           move "Voice of the Soul" to sname of death-metal.
           move 121 to bpm of death-metal.
           move "The Spirit of Radio" to sname of prog-rock.
           move 136104 to bpm of prog-rock.

           display sname of prog-rock " has bpms " bpm of prog-rock.
           display "I love " top-artist.

           stop run
           .
