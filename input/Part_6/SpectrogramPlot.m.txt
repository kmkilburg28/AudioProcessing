searchFiles = [
	"areacode1.wav", ...
	"areacode2.wav", ...
	"areacode3.wav"
];
imageFiles = [
	"../../output/Part_6/areacode1.png", ...
	"../../output/Part_6/areacode2.png", ...
	"../../output/Part_6/areacode3.png"
];

codes = [
	3 1 9;
	5 1 0;
	6 3 1
];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Generate Area Codes
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Setup Pause Time
samplingFreq = 44100;
dialLength = 0.5;
pauseLength = dialLength/2;
pauseTime = 0 : 1/samplingFreq : pauseLength;
pauseWave = sin(pauseTime);
for i = 1:length(codes)
	wave = 0;
	code = codes(i,:);
	for codeInd = 1:length(code)
		wave = [wave dial_digit(int2str(code(codeInd)), dialLength, samplingFreq)];
		wave = [wave pauseWave];
	end
	audiowrite(searchFiles(i), wave, samplingFreq)
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Read from a WAV file and plot the Spectrogram
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
for (i = 1:searchFiles.length())
	[Y,fs]=audioread(searchFiles(i)); % read the WAV file

	% Y   - audio data samples
	% 512 - window size  (in samples)
	% 256 - overlap      (in samples)
	% 512 - FFT size     (in samples)
	% fs  - sampling frequency (in Hz)
	% 'yaxis' - put the frequencies along the y axis
	spectrogram(Y, 512, 256, 512, fs, 'yaxis');
	title('Spectrogram for ' + searchFiles(i));
	saveas(gcf, imageFiles(i));
end