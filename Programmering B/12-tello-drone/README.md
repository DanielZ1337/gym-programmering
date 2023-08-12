# Drone projekt

[Tidligere oplæg](https://bitbucket.org/zbc_slagelse_htx/workspace/projects/B18)

---

- [Drone projekt](#drone-projekt)
    - [Rammer](#rammer)
    - [Corona](#corona)
    - [Begreber](#begreber)
    - [OBS](#obs)
    - [Supplerende værktøjer til afprøvning og fejlfinding](#supplerende-værktøjer-til-afprøvning-og-fejlfinding)
    - [Dokumentation og referencer](#dokumentation-og-referencer)
    - [Vejledning](#vejledning)
        - [Uge 33](#uge-33)
        - [Generelt](#generelt)
    - [Forslag til udvidelser](#forslag-til-udvidelser)
    - [Logbog](#logbog)

---

## Rammer

- Dette oplæg opdateres løbende.
- Individuelt arbejde eller små grupper: 1-3 personer.
- Arbejde og logbog skal holdes opdateret i repo på bitbucket. Husk at tilføje jacs@zbc.dk til repo.
- Projektet afsluttes med demonstrationer i uge 38.
- Overordnet mål: Vha. wifi (UDP) at sende kommandoer til drone og modtage svar, telemetri data samt videosignal. Se [vejledningsafsnittet](#vejledning).

---

## Corona

Husk at spritte jeres arbejdsborde af før I forlader dem.

---

## Begreber

- Funktioner som argumenter
- Biblioteksmoduler
- Kommunikation mellem programmer (grænseflader)
- Netværkskommunikation (UDP)
- Parallel programmering / Asynkron programmering

---

## OBS

- Dronerne larmer under flyvning - flyv kun udenfor (vindstille) eller i aftalte lokaler (JM-salen).
- PAS PÅ DRONERNE - både før, under og efter flyvning.
- Batteri: 13 minutters flyvetid og over 1 times opladning.
- Dronerne kan blive varme i bunden, hvis de står længe uden at flyve.

---

## Supplerende værktøjer til afprøvning og fejlfinding

- Tello Drone app til mobil: [android](https://play.google.com/store/apps/details?id=com.ryzerobotics.tello&hl=en) [iPhone](https://apps.apple.com/us/app/tello/id1330559633)
- [Wireshark](https://www.wireshark.org/download.html) til at overvåge netværkspakker på computer.
- UDP sender/modtager til mobil: [Packetron til android](https://play.google.com/store/apps/details?id=com.tetron.packetron&hl=en) (der kan svares på pakker ved at trykke på den modtagede besked)

---

## Dokumentation og referencer

- [Tello Drone SDK 2 user guide](https://www.ryzerobotics.com/tello-edu/downloads)
- [ASIO](https://think-async.com/Asio/asio-1.16.1/doc/) (mest brugbart er Overview, Tutorial, Examples og Reference)
- [OpenCV](https://docs.opencv.org/4.3.0/)

---

## Vejledning

### Uge 33

- Følg [opsætning](https://bitbucket.org/zbc_slagelse_htx/12-tello-drone/wiki/Home) og tjek om `main.cpp` kan kompileres og køres korrekt.

- UDP client (send kommando og modtag svar)
    - Undersøg [UDP client eksempel](eksempler/UDP_client.cpp) og modificer det, så der kan kommunikeres med din telefon fx vha. Packetron til android. (Kræver muligvis at portene åbnes i en evt. firewall.)
    - Undersøg vha. dokumentationen for dronen hvilken IP og port der skal bruges for at sende kommandoer til dronen. Afprøv ved at sende "command" til dronen og se om der kommer svar tilbage som forventet. Hvis der er mulighed for flyvning (se [OBS!](#obs)) kan man lette vha. "takeoff" og lande igen vha. "land".
    - Lav en klasse til objekter der kan bruges til at sende kommandoer til dronen. Klassen skal have en metode til at sende kommandoer og en metode til at modtage svar.

- Video med openCV
    - Læs [eksemplet med video](eksempler/local_video.cpp).
    - Fjern delen som "spoler" 2 sekunder frem i videoen og lav i stedet en løkke som hele tiden indlæser 1 frame og viser den. `cv::waitKey()` kan bruges til at styre tiden hver frame er vist ved at angive en funktionsargument som er tid i millisekunder. Programmet skal stoppe når hele videoen er afspillet.
    - Undersøg hvordan dronen kan gives besked på at streame video og find ud af hvilken adresse det skal opfanges på. `cv::VideoCapture` objektet kan derefter initialiseres med `"udp://yyy.yyy.yyy.yyy:zzzzz"` hvor ip og port indsættes. Se om du kan streame video fra dronen.
    - VideoCapture modulet udskriver muligvis en hel del fejl/oplysninger under streaming. Det kan evt. videregives til en tekstfil vha. `freopen("errors.log","w",stderr);` (se evt. [link](http://www.cplusplus.com/reference/cstdio/freopen/)) så det ikke fylder hele konsollen.

- UDP server (modtag telemetri data)
    - Undersøg [UDP server eksempel](eksempler/UDP_server.cpp) og modificer det, så du kan modtage data fra dronen.
    - Undersøg vha. dokumentationen for dronen hvilken port der skal bruges for at modtage data fra dronen. Afprøv det.
    - Lav en klasse til objekter der kan modtage data fra dronen. Bedøm selv om informationerne skal skrives til en tekstfil eller om det skal fortolkes og gemmes i en datastruktur.

### Generelt

- Prøv at få samlet ovenstående funktionaliteter i samme program, fx ved at opdele i objekter efter deres formål og ved at opdele koden logisk i flere filer. Man kan også have 3-lagsarkitekturen (data, logik, præsentation) i baghovedet under sin opdeling.

- Gør noget ud af at programmet kan afvikles så gnidningsfrit så muligt og at beskeder og fejlbeskeder bliver udskrevet hensigtsmæssigt. Det kan være en god idé at nogle ting skrives til tekstfiler i stedet for at fylde konsollen til.

- Gør din kode læsevenlig. En del tid i projekter bruges ofte på at skrive kode pænere og mere forståeligt uden at ændre på funktionaliteten (såkaldt refactoring).

- Skriv kommentarer/dokumentation til din kode og lav klassediagrammer til klasserne.

---

## Forslag til udvidelser

- Styring vha. taster
- Flighttracker
- Objektgenkender
- Bruge [Low-Level Protocol](https://tellopilots.com/wiki/protocol/) til fx at tage et enkelt billede.

---

## Logbog

Beskriv hvilke konstrolstrukturer eller datastrukturer du har arbejdet med og hvorfor de passer ind i den valgte løsning. Derudover kan du få yderligere inspiration

- User Datagram Protocol (UDP)
- Kommunikation til/fra drone
- Datastrukturen `cv::Mat` og hvordan det kan bruges til billeder
