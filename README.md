<h1>Wordle Helper - C</h1>

<p>This is a small C application I built to assist in making the most effective guesses in Wordle. This project was inspired by the sheer domination I was facing trying to compete with someone in the daily Wordle.</p>

<p><i>To run the Wordle helper</i>:</p>
<ol>
<li>Run the command 'make re' (This creates the executable, compiling all necessary files)</li>
<li>Run the executable ('./wordle-solver'), using the required arguments</li>
<li>Repeat step 2, updating the arguments as you solve the Wordle further</li>
</ol>

<p>For the executable to run, it requires 5 arguments<sup>0</sup>.</p>

<p><i>The arguments<sup>1</sup> are as follows</i>:</p>

<ol start="0">
<li>Executable name ('./wordle-solver')</li>
<li>Dictionary<sup>2</sup> of words to use ('./dicts/answers\_wordle.txt')</li>
<li>Current correct letters<sup>3</sup> ('..a.e')</li>
<li>Letters contained in answer, but not in correct spot ('t')</li>
<li>Letters not contained in answer ('sl')</li>
</ol>

<p>Example: ./wordle-solver ./dicts/answers\_wordle.txt '..a.e' 't' 'sl'

<p>The above example would be the command run after the guess 'slate' was input into Wordle, when the answer is 'trace'</p>

<p><i>Notes</i>:</p>

<ol start="0">
<li>Please ensure all arguments are in lowercase, I haven't done any handling of uppercase letters</li>
<li>The number out the front of the argument denotes the argument number in the program</li>
<li>There are two dictionaries I provide to choose from pulled from NYTimes lists of valid answers and guesses. With a recent change to how they pick the word of the day, occassionally the answer is chosen from the valid guesses list. An example of this is 'Kazoo' which was the solution on the 19 June 2023. I always start with the answers dictionary, and if it doesn't show up, I move to the guesses dictionary.</li>
<li>The current correct letters argument must have 5 characters! In the event you don't know the letter for that spot, you need to use the '.' character as a placeholder</li>
</ol>

<p>As always, if you see any issues with my code or think I could improve it (whether it be in regards to time or space complexity, or anything at all), please let me know! (Probably by forking my repo and putting your own solution up with comments for me to see).</p>
