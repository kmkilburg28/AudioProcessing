%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Read from a WAV file and plot the Spectrogram
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
searchFiles = [
	"ball_bounce_brick_mono.wav", ...
	"ball_bounce_paddle_mono.wav", ...
	"paddle_widening_mono.wav"
];
printNames = [
	"ball\_bounce\_brick\_mono.wav", ...
	"ball\_bounce\_paddle\_mono.wav", ...
	"paddle\_widening\_mono.wav"
];
imageFiles = [
	"../../output/Part_4/spect_ball_bounce_brick_mono.png", ...
	"../../output/Part_4/spect_ball_bounce_paddle_mono.png", ...
	"../../output/Part_4/spect_paddle_widening_mono.png"
];

for (i = 1:searchFiles.length())
    [Y,fs]=audioread(searchFiles(i)); % read the WAV file

    % Y   - audio data samples
    % 512 - window size  (in samples)
    % 256 - overlap      (in samples)
    % 512 - FFT size     (in samples)
    % fs  - sampling frequency (in Hz)
    % 'yaxis' - put the frequencies along the y axis
    spectrogram(Y, 512, 256, 512, fs, 'yaxis');
    title('Spectrogram for ' + printNames(i));
    saveas(gcf, imageFiles(i));
end