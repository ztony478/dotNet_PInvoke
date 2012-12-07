using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace ManagedUtility
{
    public class AdvancedStopwatch
    {
        private Stopwatch _watch;
        private List<long> _recordList;

        public AdvancedStopwatch()
        {
            _watch = new Stopwatch();
            _recordList = new List<long>();
        }

        public void Start()
        {
            _watch.Start();
        }

        public void Stop()
        {
            _watch.Stop();
        }

        public void Reset()
        {
            _watch.Reset();
            _recordList = new List<long>();
        }

        public void Record()
        {
            _recordList.Add(_watch.ElapsedMilliseconds);
        }

        public List<long> Records
        {
            get { return _recordList; }
        }

    }
}
