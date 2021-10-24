%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Read from a WAV file and plot the Spectrogram
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
searchFiles = [
	"sound1.m4a", ...
	"sound2.m4a", ...
	"sound3.m4a"
];
imageFiles = [
	"../../output/Part_5/sound1.png", ...
	"../../output/Part_5/sound2.png", ...
	"../../output/Part_5/sound3.png"
];

for (i = 1:searchFiles.length())
    [Y,fs]=audioread(searchFiles(i)); % read the WAV file
    Y = (Y(:,1) + Y(:,2)) / 2 % turn two channel into one channel
    % Y duration is chosen to be the full length
    % sampling frequency is chosen automatically from the WAV file metadata

    % This audio was recorded by opening Stardew Valley on my MacBook, turning off the music and turning interactive sounds on, recording a few interactions with QuickTime Player, and then trimming the audio clips to smaller durations with QuickTime Player.

    % Y   - audio data samples
    % 512 - window size  (in samples) (window duration)
    % 256 - overlap      (in samples)
    % 512 - FFT size     (in samples)
    % fs  - sampling frequency (in Hz)
    % 'yaxis' - put the frequencies along the y axis
    spectrogram(Y, 512, 256, 512, fs, 'yaxis');
    title('Spectrogram for ' + searchFiles(i));
    saveas(gcf, imageFiles(i));
end