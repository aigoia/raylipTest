![Image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FslIIw%2FbtsLyT9LS4u%2Fg3mwAZWQpzvZkkuWaKOoF1%2Fimg.png)

Creating simple games with Raylib is the easiest way to study C++ programming language.

# Library
- [Raylib](https://www.raylib.com/index.html)

## Quick start
### Linux

First, install and make Raylib.
- [Make Raylib in linux](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)

<div class="code-box">
  <pre><code>sudo apt install build-essential git</code></pre>
  <button onclick="copyCode(this)"></button>
</div>

Install CMake.

<div class="code-box">
  <pre><code>sudo apt install cmake</code></pre>
  <button onclick="copyCode(this)"></button>
</div>

Install Raylib.

<div class="code-box">
  <pre><code>git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON ..
make
sudo make install
sudo ldconfig</code></pre>
  <button onclick="copyCode(this)"></button>
</div>


And then, download and run this project.

<div class="code-box">
  <pre><code>sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev</code></pre>
  <button onclick="copyCode(this)"></button>
</div>

<div class="code-box">
  <pre><code>git clone https://github.com/aigoia/raylipTest.git</code></pre>
  <button onclick="copyCode(this)"></button>
</div>

<div class="code-box">
  <pre><code>cd raylipTest</code></pre>
  <button onclick="copyCode(this)"></button>
</div>

<div class="code-box">
  <pre><code>bash build.bash</code></pre>
  <button onclick="copyCode(this)"></button>
</div>

- [How to use bash](https://youtu.be/fJfmhhPMV40?si=-qXJhlDw1JctydGR)
