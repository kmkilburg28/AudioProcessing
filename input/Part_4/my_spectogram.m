function my_spectogram(x, windowSize, overlapSize)

% fft(X,N) is the N-point fft, padded with zeros if X has less
% than N points and truncated if it has more. (From the manual).

interval = windowSize - overlapSize;
startLocs = 1:interval:length(x);
startLocs = startLocs(length(x) - startLocs >= windowSize)
sample_transforms = zeros(

for i = 1:length(startLocs)
    startLoc = startLocs(i);
    window_sample = x(startLoc:startLoc+windowSize);
    X = fft(x,length(x));   % compute the FFT of x

    % Shuffle the frequencies returned by the FFT
    % to order them from negative to positive.
    % The function swaps the left and the right part of the vector, e.g.,
    % fftshift([0,1,2,3,4,5,6,7])  ->>  [4 5 6 7 0 1 2 3]
%     X = fftshift(X);

    % spectrogram(Y, 512, 256, 512, fs, 'yaxis');
end