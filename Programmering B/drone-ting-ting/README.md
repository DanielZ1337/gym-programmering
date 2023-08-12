# Logbog #

TELLA-59FA79

## 12/08-2020 ##
Vi har fået sat UDP-klienten op. SDK mode virker, og vi har testet "takeoff" kommandoen, som gør, at den selv har afgang - begge ting virker. Man kan kun sende en kommando v.h.a **string send_buffer**, hver eneste gang, man compiler. Hvis man skal sende en ny kommando til dronen, så skal man lukke programmet og ændre stringen send_buffer. Der skal arbejdes på, at man skal kunne sende kommandoer til dronen løbende og kontinuerligt.

## 14/08-2020 ##
Vi har udvidet programmet til at kunne modtage flere kommandoer. Det har vi gjort ved hjælp af et **while** loop med en **cin** funktion i, som gør, at man kan skrive nye kommandoer løbende. Når man har givet komandoen "land", skal man lukke programmet og starte det igen for at give nye kommandoer. Den ville til at starte med ikke give nogen respons tilbage. Vi har taget respons-delen ind i **void sendCommand()**'s **while** loop. Derefter har vi gjort sådan så man kan skrive "flip x", hvor det er, at x ikke er et tal, det er et bogstav, så derfor tog den hele linjen opdelt som hver sin kommando. Det er blevet fikset vha. '\n' delimiter aller sidst, så **getline** funktionen kommer til at være følgende: **getline(cin, send_buffer, '\n')**. Dette gør, at hele linjen man skriver er en hel kommando.

## 17/08-2020 ##
Vi skal få kameraet/video-stream til at virke.

## 21/08-2020 ##
Vi har fået kameraet til at give os video, som dog har lidt delay. 
Vi er begyndt at implemetere **waitKey()** som gør vi kan styre dronen med tasterne på keyboard

## 26/08-2020 ##
Vi har prøvet at fået keypress til at virke

## 04/09-2020 ##
Vi har fået keypress til at virke er er så småt begyndt at få rydt op i koden. Vi har også fået RC-control til at fungere